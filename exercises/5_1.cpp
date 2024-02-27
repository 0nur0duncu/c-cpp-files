#include<iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    //------------------- 1 -------------------------
    /* int i=0;
    for(;i<=12;){
        cout << i * i * i<<endl;
        i+=3;
    } */

    //------------------- 2 -------------------------

    /* int toplam = 0,sayi;
    cout<< "Cikis yapmak icin -1 giriniz"<<endl;
    do{
        cout<<"Bir sayi giriniz...:";
        cin>> sayi;
        if (sayi == -1) break;
        toplam +=sayi;
    }while (true);
    cout <<"toplam "<<toplam << endl; */

    //------------------- 3 -------------------------

    /* int sayi,fakt = 1;
    cout<< "Lutfen sayi giriniz...:";
    cin>> sayi;
    while (sayi-->1)
    {
        fakt *=sayi;
    }
    cout << "Faktoriyel Sonuc -->" <<fakt<<endl; */

    //------------------- 4 -------------------------

/*  for(int i = 2 ; i <= 500; i++){
        bool durum = true;
        for (int j = i-1; j>1;j--)
        {
            if (i % j == 0){ durum = false; break;}      
        }
        if (durum) cout <<i<<"\t";  
    } */

    //------------------- 5 -------------------------

    /* int sayi1,sayi2,enb,enk;
    cout << "Birinci sayiyi giriniz :";
    cin>> sayi1;
    cout << "Ikinci sayiyi giriniz :";
    cin>> sayi2;
    enb = sayi1 > sayi2 ? sayi1 : sayi2;
    enk = sayi1 < sayi2 ? sayi1 : sayi2;
    do{
        cout << ++enk<<"\n";
    }while(enk < enb -1); */

    //------------------- 6 -------------------------

    /* int toplam = 0;
    for(int i = 40;i >=4;i--){
        if (i % 2 == 0) toplam +=i;
    }
    cout << "toplam --> " << toplam<<endl; */

    //------------------- 7 -------------------------

    /* int toplam = 0;
    for ( int i = 1 ; i <= 1000 ; i++){
        if (i % 5 == 0 && i% 7 != 0) toplam +=i;
    }
    cout << "toplam --> " << toplam<<endl; */

    //------------------- 8 -------------------------

    /* int sayi1,sayi2,enb,enk,toplam = 0;
    cout << "Birinci sayiyi giriniz :";
    cin>> sayi1;
    cout << "Ikinci sayiyi giriniz :";
    cin>> sayi2;
    enb = sayi1 > sayi2 ? sayi1 : sayi2;
    enk = sayi1 < sayi2 ? sayi1 : sayi2;

    for ( int i = enk ; i <= enb ; i++){
        for (int j = i-1; j >= 1; j--) 
        if(i % j ==0) toplam += j;
        if (i == toplam) cout<<i<<endl;
        toplam = 0;
    } */

    //------------------- 9 -------------------------

    int toplam = 0;

    for(int i=100;i<=999;i++){
        int birler,onlar,yuzler;
        yuzler = i / 100;
        onlar = (i % 100) / 10;
        birler = (i % 100) % 10;
        if ((birler *birler *birler + onlar*onlar*onlar + yuzler* yuzler* yuzler) == i) cout<<i<<endl;
    }

    system("PAUSE");
    return 0;
}
