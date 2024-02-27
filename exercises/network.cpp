#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data);

int main(int argc, char **argv) {
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    struct bpf_program fp;
    char filter_exp[] = "tcp";
    bpf_u_int32 net;
    bpf_u_int32 mask;

    if(argc < 2) {
        printf("Usage: %s <interface>\n", argv[0]);
        return 1;
    }

    if(pcap_lookupnet(argv[1], &net, &mask, errbuf) == -1) {
        printf("Couldn't get netmask for device %s: %s\n", argv[1], errbuf);
        net = 0;
        mask = 0;
    }

    handle = pcap_open_live(argv[1], BUFSIZ, 1, 1000, errbuf);
    if(handle == NULL) {
        printf("Couldn't open device %s: %s\n", argv[1], errbuf);
        return 1;
    }

    if(pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        printf("Couldn't compile filter: %s\n", pcap_geterr(handle));
        return 1;
    }

    if(pcap_setfilter(handle, &fp) == -1) {
        printf("Couldn't set filter: %s\n", pcap_geterr(handle));
        return 1;
    }

    pcap_loop(handle, -1, packet_handler, NULL);

    pcap_close(handle);
    return 0;
}

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data) {
    struct iphdr *ip_hdr;
    struct tcphdr *tcp_hdr;
    int tcp_hdr_len;

    ip_hdr = (struct iphdr *)(pkt_data + sizeof(struct ether_header));
    tcp_hdr = (struct tcphdr *)(pkt_data + sizeof(struct ether_header) + sizeof(struct iphdr));
    tcp_hdr_len = tcp_hdr->doff * 4;

    printf("Source IP: %s\n", inet_ntoa(*(struct in_addr *)&ip_hdr->saddr));
    printf("Destination IP: %s\n", inet_ntoa(*(struct in_addr *)&ip_hdr->daddr));
    printf("Source Port: %d\n", ntohs(tcp_hdr->source));
    printf("Destination Port: %d\n", ntohs(tcp_hdr->dest));
    printf("TCP Flags: %x\n", tcp_hdr->th_flags);
}
