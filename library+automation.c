#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <unistd.h> // sleep komutu için
#include <conio.h>
#include <time.h> //rassallaştırırken time(NULL) için

/* Kitap işlemleri ve kullanılan metodları*/
// prototip
void kitapIslemleri();
struct Kitap {
	int kitapNo;
	char kitapIsim[50]; 
	char yazarAdiSoyadi[50];
	int oduncDurumu; // 0 olurssa kitap daha ödünç alınmamış, 1 ödünç alınmış
};
int randomNumaraUret();
void kitapEkle();
void kitapListele();
void kitapGuncelle(int guncellenecekKitapNo);
void kitapSil(int silinecekKitapNo);
void kitapAra(const char arananKelime[]);


/* Kullanıcı işlemleri ve kullanılan metodları*/
void kullaniciIslemleri();
struct Kullanici {
	int kullaniciNo;
	char kullaniciAdiSoyadi[50]; 
};
void kullaniciEkle();
void kullaniciListele();
void kullaniciGuncelle(int guncellenecekKullaniciNo);
void kullaniciSil(int silinecekKullaniciNo);
void kullaniciAra(const char arananKelime[]);

/* Ödünç işlemleri ve kullanılan metodları*/
void oduncIslemleri();
void oduncAl(const char GeciciKullaniciAdiSoyadi[],int GecicikullaniciNo); // kitap ödünç durumu 0 dan 1 oluyor
void kitabiGeriGetir(int kullaniciNo, int kitapNo); // kitap ödünç durumu 1 den 0 oluyor
void oduncListele();


int main(int argc, char const *argv[])
{
    // setlocale(LC_ALL, "Turkish"); 
    int anaMenuSecimi;
    int hataliSecim = 0;
    // while(1), for(;;) sonsuz döngü için kullandım
    for(;;) {
        
        printf("\n******************************************\n");
        printf("*                                        *\n");
        printf(  "*          KÜTÜPHANE OTOMASYONU          *\n");
        printf("*                                        *\n");
        printf("******************************************\n");
        printf("*                                        *\n");
        printf("*       1 >>> Kitap İşlemleri            *\n");
        printf("*                                        *\n");
        printf("******************************************\n");
        printf("*                                        *\n");
        printf("*       2 >>> Kullanıcı İşlemleri        *\n");
        printf("*                                        *\n");
        printf("******************************************\n");
        printf("*                                        *\n");
        printf("*       3 >>> Ödünç Alma İşlemleri       *\n");
        printf("*                                        *\n");
        printf("******************************************\n");
        printf("* Seçiminiz ?> ");
        scanf("%d", &anaMenuSecimi);

        switch (anaMenuSecimi) {
            case 1:
                system("cls"); // ekranı temizle
                printf("Kitap işlemlerine yönlendiriliyor...");
                sleep(1);
                system("cls");
                kitapIslemleri();
                hataliSecim = 0;
                break;
            case 2:
                system("cls"); 
                printf("Kullanıcı işlemlerine yönlendiriliyor...");
                sleep(1);
                system("cls");
                kullaniciIslemleri();
                hataliSecim = 0;
                break;
            case 3:
                system("cls"); 
                printf("Ödünç işlemlerine yönlendiriliyor...");
                sleep(1);
                system("cls");
                oduncIslemleri();
                hataliSecim = 0;
                break;
            default:
                system("cls"); 
                ++hataliSecim;
                printf("!!! Hatalı seçim yaptınız kalan hakkınız %d\n",3 - hataliSecim);
                if(hataliSecim == 3)
                {
                    printf("3 hatalı seçim yaptınız programdan çıkılıyor...");
                    sleep(1); // 2 saniye programı beklet
                    exit(0); // programı bitiriyor
                };
        }
    }
    return 0;
}

void kitapIslemleri()
{
    int kitapIslemleriSecimi;
    int kitapIslemlerihataliSecim = 0;
    int kitapIslemleriDurum = 1; // ana menüye dönebilmek için
    
    while(kitapIslemleriDurum == 1) {
        
        printf("\n******************************************\n");
        printf("*                                        *\n");
        printf("*          KİTAP İŞLEMLERİ               *\n");
        printf("*                                        *\n");
        printf("******************************************\n");
        printf("*                                        *\n");
        printf("*       1 >>> Kitap Ekleme               *\n");
        printf("*                                        *\n");
        printf("******************************************\n");
        printf("*                                        *\n");
        printf("*       2 >>> Kitap Listeleme            *\n");
        printf("*                                        *\n");
        printf("******************************************\n");
        printf("*                                        *\n");
        printf("*       3 >>> Kitap Güncelleme           *\n");
        printf("*                                        *\n");
        printf("******************************************\n");
        printf("*                                        *\n");
        printf("*       4 >>> Kitap Silme                *\n");
        printf("*                                        *\n");
        printf("******************************************\n");
        printf("*                                        *\n");
        printf("*       5 >>> Kitap Arama                *\n");
        printf("*                                        *\n");
        printf("******************************************\n");
        printf("*                                        *\n");
        printf("*       6 >>> Ana Menüye Dön             *\n");
        printf("*                                        *\n");
        printf("******************************************\n");
        printf("*                                        *\n");
        printf("*       7 >>> Programdan Çık             *\n");
        printf("*                                        *\n");
        printf("******************************************\n");
        printf("* Seçiminiz ?> ");
        scanf("%d", &kitapIslemleriSecimi);

        switch (kitapIslemleriSecimi) {
            case 1:
                system("cls"); 
                kitapEkle();
                kitapIslemlerihataliSecim = 0;
                break;
            case 2:
                system("cls");
                kitapListele();
                printf("Kitap işlemleri menüsüne geri dönmek için bir tuşa basınız >>\n");
                getche();
                system("cls");
                printf("Kitap işlemleri menüsüne geri dönülüyor...\n");
                sleep(1);
                kitapIslemlerihataliSecim = 0;
                break;
            case 3:
                system("cls");
                kitapListele();
                int guncellenecekKitapNo;
                printf("Güncelleme istediğiniz kitap numarasını giriniz >> ");
                scanf("%d",&guncellenecekKitapNo);
                system("cls");
                kitapGuncelle(guncellenecekKitapNo);
                system("cls");
                kitapListele();
                printf("Kitap işlemleri menüsüne geri dönmek için bir tuşa basınız >>\n");
                getche(); // kullanıcının girdiği tek karakterlik tuşu alır
                system("cls");
                printf("Kitap işlemleri menüsüne geri dönülüyor...\n");
                sleep(1);
                kitapIslemlerihataliSecim = 0;
                break;
            case 4:
                system("cls");
                kitapListele();
                int silinecekKitapNo;
                printf("Silmek istediğiniz kitap numarasını giriniz >> ");
                scanf("%d",&silinecekKitapNo);
                kitapSil(silinecekKitapNo);
                system("cls");
                sleep(1);
                system("cls");
                kitapListele();
                printf("Kitap işlemleri menüsüne geri dönmek için bir tuşa basınız >>\n");
                getche();
                system("cls");
                printf("Kitap işlemleri menüsüne geri dönülüyor...\n");
                sleep(1);
                kitapIslemlerihataliSecim = 0;
                break;
            case 5:
                system("cls");
                char arananKelime[50];
                printf("Anahtar kelimeleri giriniz >> ");
                scanf("%s",arananKelime);
                kitapAra(arananKelime);
                printf("Kitap işlemleri menüsüne geri dönmek için bir tuşa basınız >>\n");
                getche();
                system("cls");
                printf("Kitap işlemleri menüsüne geri dönülüyor...\n");
                sleep(1);
                kitapIslemlerihataliSecim = 0;
                break;
            case 6:
                system("cls");
                printf("Ana menüsüye geri dönülüyor...\n");
                sleep(1);
                system("cls");
                kitapIslemleriDurum = 0; // eşitliği bozup ana menüye geri dönmesi için yazdım
                break;
            case 7:
                system("cls"); 
                printf("Programdan çıkılıyor...");
                sleep(1);
                exit(0); // programdan çıkıyor
            default:
                system("cls"); 
                ++kitapIslemlerihataliSecim;
                printf("!!! Hatalı seçim yaptınız kalan hakkınız %d\n",3 - kitapIslemlerihataliSecim);
                if(kitapIslemlerihataliSecim == 3)
                {
                    printf("3 hatalı seçim yaptınız programdan çıkılıyor...");
                    sleep(1);
                    exit(0);
                };
        }
    }
}

int randomNumaraUret() {
    srand((int)time(NULL)); // rassallaştırmak
    return rand() % 9000000 + 1000000;
}

void kitapEkle() {
    FILE *dosya; //stdio.h kütüphanesi içerisinde
    struct Kitap yeniKitapEkle;

    dosya = fopen("kitapVeriTabani.txt", "ab"); // append + binary olarak açar
    // dosya yoksa oluşturuyor da
    // fopen dosyayı açar
    if (dosya == NULL) {
        fprintf(stderr, "Dosya açılırken hata oluştu!\n"); // stderr hata olsun diye
        sleep(1);
        system("cls");
        return;
    }

    yeniKitapEkle.kitapNo = randomNumaraUret();

    printf("Kitap Adı: ");
    scanf("%s",yeniKitapEkle.kitapIsim); // tek satır alıyor

    printf("Yazar Adı-Soyadı: ");
    scanf("%s", yeniKitapEkle.yazarAdiSoyadi);

    yeniKitapEkle.oduncDurumu = 0;

    fwrite(&yeniKitapEkle, sizeof(struct Kitap), 1, dosya); // dosyaya yazdırmak için

    fclose(dosya); // dosyayı kapatır.
    system("cls"); 

    printf("Kitap başarıyla eklendi.\n");
    printf("Kitap işlemleri menüsüne geri dönülüyor...\n");
    sleep(1);
}
void kitapListele() {
    FILE *dosya;
    dosya = fopen("kitapVeriTabani.txt", "rb");

    if (dosya == NULL) {
        fprintf(stderr, "Dosya açılırken hata oluştu!\n");
        sleep(1);
        return;
    }

    struct Kitap okunanKitap;

    while (fread(&okunanKitap, sizeof(struct Kitap), 1, dosya) == 1) {
        printf("Kitap No: %d\n", okunanKitap.kitapNo);
        printf("Kitap Adı: %s\n", okunanKitap.kitapIsim);
        printf("Yazar Adı-Soyadı: %s\n", okunanKitap.yazarAdiSoyadi);
        printf("Ödünç Durumu: %d\n", okunanKitap.oduncDurumu);
        printf("----------------------------\n");
    }
    fclose(dosya);
}
void kitapGuncelle(int guncellenecekKitapNo) {
    FILE *dosya;

    dosya = fopen("kitapVeriTabani.txt", "r+b"); // r+ hem okuma hem yazma yapmak için

    if (dosya == NULL) {
        fprintf(stderr, "Dosya açılırken hata oluştu!\n");
        sleep(1);
        return;
    }

    struct Kitap guncelKitap;

    int guncellemeDurum = 0;
    while (fread(&guncelKitap, sizeof(struct Kitap), 1, dosya) == 1) {
        if (guncelKitap.kitapNo == guncellenecekKitapNo) {

            printf("Yeni kitap adı: ");
            scanf("%s", guncelKitap.kitapIsim);

            printf("Yeni yazar Adı-Soyadı: ");
            scanf("%s", guncelKitap.yazarAdiSoyadi);

            printf("Yeni ödünç durumu (0:Ödünç Alınabilir, 1:Ödünç Alınamaz): ");
            scanf("%d", &guncelKitap.oduncDurumu);

            fseek(dosya, -(int)sizeof(struct Kitap), SEEK_CUR);

            if (fwrite(&guncelKitap, sizeof(struct Kitap), 1, dosya) != 1) {
                fprintf(stderr, "Dosya açılırken hata oluştu!\n");
                return;
            }
            system("cls");
            printf("Güncelleme işlemini onaylıyor musunuz (Evet[1] Hayır[0]) >>");
            scanf("%d",&guncellemeDurum);
            if(guncellemeDurum == 1){
                printf("Kitap başarıyla güncellendi.");
                break;
            }
        }
    }

    fclose(dosya);
}


void kitapSil(int silinecekKitapNo) {
    FILE *dosya, *geciciDosya;

    dosya = fopen("kitapVeriTabani.txt", "rb");

    if (dosya == NULL) {
        fprintf(stderr, "Dosya açma hatası!\n");
        return;
    }

    geciciDosya = fopen("geciciKitapVeriTabani.txt", "wb");

    if (geciciDosya == NULL) {
        fprintf(stderr, "Geçici dosya açılırken hata oluştu!\n");
        fclose(dosya);
        return;
    }

    struct Kitap silinenKitap;

    while (fread(&silinenKitap, sizeof(struct Kitap), 1, dosya) == 1) {
        if (silinenKitap.kitapNo != silinecekKitapNo) {
            fwrite(&silinenKitap, sizeof(struct Kitap), 1, geciciDosya);
        }
    }

    fclose(dosya);
    fclose(geciciDosya);

    if (remove("kitapVeriTabani.txt") == 0 &&
        rename("geciciKitapVeriTabani.txt", "kitapVeriTabani.txt") == 0) {
        printf("Kitap başarıyla silindi.\n");
    } else {
        fprintf(stderr, "Kitap silme hatası!\n");
    }
}

void kitapAra(const char arananKelime[]) {
    FILE *dosya;

    dosya = fopen("kitapVeriTabani.txt", "rb");

    if (dosya == NULL) {
        fprintf(stderr, "Dosya açılırken hata oluştu!\n");
        sleep(1);
        return;
    }

    struct Kitap arananKitap;

    while (fread(&arananKitap, sizeof(struct Kitap), 1, dosya) == 1) {
        if (strstr(arananKitap.kitapIsim, arananKelime) != NULL) {
            
            printf("Kitap No: %d\n", arananKitap.kitapNo);
            printf("Kitap Adı: %s\n", arananKitap.kitapIsim);
            printf("Yazar Adı Soyadı: %s\n", arananKitap.yazarAdiSoyadi);
            printf("Ödünç Durumu: %d\n", arananKitap.oduncDurumu);
            printf("----------------------------\n");
        }
    }

    fclose(dosya);
}


void kullaniciIslemleri(){
    int kullaniciIslemleriSecimi;
    int kullaniciIslemlerihataliSecim = 0;
    int kullaniciIslemleriDurum = 1;
    
    while(kullaniciIslemleriDurum == 1) {
        
        printf("\n******************************************\n");
        printf("*                                        *\n");
        printf("*          KULLANICI İŞLEMLERİ           *\n");
        printf("*                                        *\n");
        printf("******************************************\n");
        printf("*                                        *\n");
        printf("*       1 >>> Kullanıcı Ekleme           *\n");
        printf("*                                        *\n");
        printf("******************************************\n");
        printf("*                                        *\n");
        printf("*       2 >>> Kullanıcı Listeleme        *\n");
        printf("*                                        *\n");
        printf("******************************************\n");
        printf("*                                        *\n");
        printf("*       3 >>> Kullanıcı Güncelleme       *\n");
        printf("*                                        *\n");
        printf("******************************************\n");
        printf("*                                        *\n");
        printf("*       4 >>> Kullanıcı Silme            *\n");
        printf("*                                        *\n");
        printf("******************************************\n");
        printf("*                                        *\n");
        printf("*       5 >>> Kullanıcı Arama            *\n");
        printf("*                                        *\n");
        printf("******************************************\n");
        printf("*                                        *\n");
        printf("*       6 >>> Ana Menüye Dön             *\n");
        printf("*                                        *\n");
        printf("******************************************\n");
        printf("*                                        *\n");
        printf("*       7 >>> Programdan Çık             *\n");
        printf("*                                        *\n");
        printf("******************************************\n");
        printf("* Seçiminiz ?> ");
        scanf("%d", &kullaniciIslemleriSecimi);

        switch (kullaniciIslemleriSecimi) {
            case 1:
                system("cls"); 
                kullaniciEkle();
                kullaniciIslemlerihataliSecim = 0;
                break;
            case 2:
                system("cls");
                kullaniciListele();
                printf("Kullanıcı işlemleri menüsüne geri dönmek için bir tuşa basınız >>\n");
                getche();
                system("cls");
                printf("Kullanıcı işlemleri menüsüne geri dönülüyor...\n");
                sleep(1);
                kullaniciIslemlerihataliSecim = 0;
                break;
            case 3:
                system("cls");
                kullaniciListele();
                int guncellenecekKullaniciNo;
                printf("Güncelleme istediğiniz kullanıcı numarasını giriniz >> ");
                scanf("%d",&guncellenecekKullaniciNo);
                system("cls");
                kullaniciGuncelle(guncellenecekKullaniciNo);
                sleep(1);
                system("cls");
                kullaniciListele();
                printf("Kullanıcı işlemleri menüsüne geri dönmek için bir tuşa basınız >>\n");
                getche();
                system("cls");
                printf("Kullanıcı işlemleri menüsüne geri dönülüyor...\n");
                sleep(1);
                kullaniciIslemlerihataliSecim = 0;
                break;
            case 4:
                system("cls");
                kullaniciListele();
                int silinecekKullaniciNo;
                printf("Silmek istediğiniz kullanıcı numarasını giriniz >> ");
                scanf("%d",&silinecekKullaniciNo);
                kullaniciSil(silinecekKullaniciNo);
                system("cls");
                sleep(1);
                system("cls");
                kullaniciListele();
                printf("Kullanıcı işlemleri menüsüne geri dönmek için bir tuşa basınız >>\n");
                getche();
                system("cls");
                printf("Kullanıcı işlemleri menüsüne geri dönülüyor...\n");
                sleep(1);
                kullaniciIslemlerihataliSecim = 0;
                break;
            case 5:
            system("cls");
                char arananKelime[50];
                printf("Anahtar kelimeleri giriniz >> ");
                scanf("%s",arananKelime);
                kullaniciAra(arananKelime);
                printf("Kullanıcı işlemleri menüsüne geri dönmek için bir tuşa basınız >>\n");
                getche();
                system("cls");
                printf("Kullanıcı işlemleri menüsüne geri dönülüyor...\n");
                sleep(1);
                kullaniciIslemleriDurum = 0;
                break;
            case 6:
                system("cls");
                printf("Ana menüsüye geri dönülüyor...\n");
                sleep(1);
                system("cls");
                kullaniciIslemleriDurum = 0;
                break;
            case 7:
                system("cls"); 
                    printf("Programdan çıkılıyor...");
                    sleep(1);
                    exit(0);
            default:
                system("cls"); 
                ++kullaniciIslemlerihataliSecim;
                printf("!!! Hatalı seçim yaptınız kalan hakkınız %d\n",3 - kullaniciIslemlerihataliSecim);
                if(kullaniciIslemlerihataliSecim == 3)
                {
                    printf("3 hatalı seçim yaptınız programdan çıkılıyor...");
                    sleep(1);
                    exit(0);
                };
        }
    }
}

void kullaniciEkle() {
    FILE *dosya;

    dosya = fopen("kullaniciVeriTabani.txt", "ab");

    if (dosya == NULL) {
        fprintf(stderr, "Dosya açılırken hata oluştu!\n");
        sleep(1);
        return;
    }

    struct Kullanici yeniKullanici;

    yeniKullanici.kullaniciNo = randomNumaraUret();

    printf("Kullanıcı Adı Soyadı: ");
    scanf("%s", yeniKullanici.kullaniciAdiSoyadi);

    fwrite(&yeniKullanici, sizeof(struct Kullanici), 1, dosya);

    fclose(dosya);
    system("cls"); 

    printf("Kullanıcı başarıyla eklendi.\n");
    printf("Kullanıcı işlemleri menüsüne geri dönülüyor...\n");
    sleep(1);
}

void kullaniciListele() {
    FILE *dosya;

    dosya = fopen("kullaniciVeriTabani.txt", "rb");
    
    if (dosya == NULL) {
        fprintf(stderr, "Dosya açılırken hata oluştu!\n");
        sleep(1);
        return;
    }

    struct Kullanici okunanKullanici;

    printf("\nKullanıcı Listesi:\n");
    printf("------------------------------------------------\n");
    printf("%-15s %-30s\n", "Kullanıcı No", "Kullanıcı Adı Soyadı");
    printf("------------------------------------------------\n");

    while (fread(&okunanKullanici, sizeof(struct Kullanici), 1, dosya) == 1) {
        printf("%-15d %-30s\n", okunanKullanici.kullaniciNo, okunanKullanici.kullaniciAdiSoyadi);
    }

    printf("------------------------------------------------\n");

    fclose(dosya);
}


void kullaniciGuncelle(int guncellenecekKullaniciNo) {
    FILE *dosya;

    dosya = fopen("kullaniciVeriTabani.txt", "r+b");

    if (dosya == NULL) {
        fprintf(stderr, "Dosya açılırken hata oluştu!\n");
        return;
    }

    struct Kullanici guncelKullanici;

    int guncellemeDurum = 0;
    while (fread(&guncelKullanici, sizeof(struct Kullanici), 1, dosya) == 1) {
        if (guncelKullanici.kullaniciNo == guncellenecekKullaniciNo) {

            printf("Yeni kullanıcı adı soyadı: ");
            scanf("%s", guncelKullanici.kullaniciAdiSoyadi);

            fseek(dosya, -(int)sizeof(struct Kullanici), SEEK_CUR);

            if (fwrite(&guncelKullanici, sizeof(struct Kullanici), 1, dosya) != 1) {
                fprintf(stderr, "Dosya yazılırken hata oluştu!\n");
                return;
            }
            printf("Güncelleme işlemini onaylıyor musunuz (Evet[1] Hayır[0]) >>");
            scanf("%d", &guncellemeDurum);
            if (guncellemeDurum == 1) {
                printf("Kullanıcı başarıyla güncellendi.\n");
                break;
            }
        }
    }

    fclose(dosya);
}
void kullaniciSil(int silinecekKullaniciNo) {
    FILE *dosya, *geciciDosya;

    dosya = fopen("kullaniciVeriTabani.txt", "rb");

    if (dosya == NULL) {
        fprintf(stderr, "Dosya açılırken hata oluştu!\n");
        return;
    }

    geciciDosya = fopen("geciciKullaniciVeriTabani.txt", "wb");

    if (geciciDosya == NULL) {
        fprintf(stderr, "Geçici dosya açılırken hata oluştu!\n");
        fclose(dosya);
        return;
    }

    struct Kullanici silinenKullanici;

    while (fread(&silinenKullanici, sizeof(struct Kullanici), 1, dosya) == 1) {
        if (silinenKullanici.kullaniciNo != silinecekKullaniciNo) {
            fwrite(&silinenKullanici, sizeof(struct Kullanici), 1, geciciDosya);
        }
    }

    fclose(dosya);
    fclose(geciciDosya);

    if (remove("kullaniciVeriTabani.txt") == 0 &&
        rename("geciciKullaniciVeriTabani.txt", "kullaniciVeriTabani.txt") == 0) {
        printf("Kullanıcı başarıyla silindi.\n");
    } else {
        fprintf(stderr, "Kullanıcı silme hatası!\n");
    }
}


void kullaniciAra(const char arananKelime[]) {
    FILE *dosya;

    dosya = fopen("kullaniciVeriTabani.txt", "rb");

    if (dosya == NULL) {
        fprintf(stderr, "Dosya açılırken hata oluştu!\n");
        return;
    }

    struct Kullanici arananKullanici;

    while (fread(&arananKullanici, sizeof(struct Kullanici), 1, dosya) == 1) {
        if (strstr(arananKullanici.kullaniciAdiSoyadi, arananKelime) != NULL) {
            printf("Kullanıcı No: %d\n", arananKullanici.kullaniciNo);
            printf("Kullanıcı Adı Soyadı: %s\n", arananKullanici.kullaniciAdiSoyadi);
            printf("----------------------------\n");
        }
    }

    fclose(dosya);
}


void oduncIslemleri()
{
    int oduncIslemleriSecimi;
    int oduncIslemlerihataliSecim = 0;
    int oduncIslemleriDurum = 1;
    
    while(oduncIslemleriDurum == 1) {
        
        printf("\n******************************************\n");
        printf("*                                        *\n");
        printf("*        Ödünç Alma İşlemleri            *\n");
        printf("*                                        *\n");
        printf("******************************************\n");
        printf("*                                        *\n");
        printf("*       1 >>> Ödünç Alma                 *\n");
        printf("*                                        *\n");
        printf("******************************************\n");
        printf("*                                        *\n");
        printf("*       2 >>> Kitabı Geri Getirme        *\n");
        printf("*                                        *\n");
        printf("******************************************\n");
        printf("*                                        *\n");
        printf("*       3 >>> Ödünç Listeleme            *\n");
        printf("*                                        *\n");
        printf("******************************************\n");
        printf("*                                        *\n");
        printf("*       4 >>> Ana Menüye Dön             *\n");
        printf("*                                        *\n");
        printf("******************************************\n");
        printf("*                                        *\n");
        printf("*       5 >>> Programdan Çık             *\n");
        printf("*                                        *\n");
        printf("******************************************\n");
        printf("* Seçiminiz ?> ");
        scanf("%d", &oduncIslemleriSecimi);

        switch (oduncIslemleriSecimi) {
            case 1:
                system("cls");
                char GeciciKullaniciAdiSoyadi[50];
                int GecicikullaniciNo;
                printf("Kullanıcı adı-soyadı >> ");
                scanf("%s",GeciciKullaniciAdiSoyadi);
                printf("Kullanıcı no >> ");
                scanf("%d",&GecicikullaniciNo);
                system("cls");
                oduncAl(GeciciKullaniciAdiSoyadi,GecicikullaniciNo);
                sleep(1);
                system("cls");
                kitapListele();
                printf("Ödünç işlemleri menüsüne geri dönmek için bir tuşa basınız >>\n");
                getche();
                system("cls");
                printf("Ödünç işlemleri menüsüne geri dönülüyor...\n");
                sleep(1);
                oduncIslemlerihataliSecim = 0;
                break;
            case 2:
                system("cls");
                int kullaniciNo, kitapNo;

                printf("Kullanıcı Numarasını Girin: ");
                scanf("%d", &kullaniciNo);

                printf("Getirilen Kitap Numarasını Girin: ");
                scanf("%d", &kitapNo);
                system("cls");
                kitabiGeriGetir(kullaniciNo,kitapNo);
                sleep(1);
                system("cls");
                kitapListele();
                printf("Ödünç işlemleri menüsüne geri dönmek için bir tuşa basınız >>\n");
                getche();
                system("cls");
                printf("Ödünç işlemleri menüsüne geri dönülüyor...\n");
                sleep(1);
                oduncIslemlerihataliSecim = 0;
                break;
            case 3:
                system("cls"); 
                oduncListele();
                printf("Ödünç işlemleri menüsüne geri dönmek için bir tuşa basınız >>\n");
                getche();
                system("cls");
                printf("Ödünç işlemleri menüsüne geri dönülüyor...\n");
                sleep(1);
                oduncIslemlerihataliSecim = 0;
                break;
            case 4:
                system("cls");
                oduncIslemleriDurum = 0;
                break;
            case 5:
                system("cls"); 
                    printf("Programdan çıkılıyor...");
                    sleep(1);
                    exit(0);
            default:
                system("cls"); 
                ++oduncIslemlerihataliSecim;
                printf("!!! Hatalı seçim yaptınız kalan hakkınız %d\n",3 - oduncIslemlerihataliSecim);
                if(oduncIslemlerihataliSecim == 3)
                {
                    printf("3 hatalı seçim yaptınız programdan çıkılıyor...");
                    sleep(1);
                    exit(0);
                };
        }
    }
}

void oduncAl(const char GeciciKullaniciAdiSoyadi[], int GeciciKullaniciNo) {
    FILE *kullaniciDosya, *kitapDosya, *oduncDosya;

    kullaniciDosya = fopen("kullaniciVeriTabani.txt", "rb");
    kitapDosya = fopen("kitapVeriTabani.txt", "r+b");
    oduncDosya = fopen("oduncVeriTabani.txt", "a");

    if (kullaniciDosya == NULL || kitapDosya == NULL || oduncDosya == NULL) {
        fprintf(stderr, "Dosya açılırken hata oluştu!\n");
        return;
    }

    struct Kullanici oduncAlanKullanici;
    int kullaniciBulundu = 0;

    while (fread(&oduncAlanKullanici, sizeof(struct Kullanici), 1, kullaniciDosya) == 1) {
        if (oduncAlanKullanici.kullaniciNo == GeciciKullaniciNo &&
            strcmp(oduncAlanKullanici.kullaniciAdiSoyadi, GeciciKullaniciAdiSoyadi) == 0) {
            kullaniciBulundu = 1;
            break;
        }
    }

    if (!kullaniciBulundu) {
        printf("Kullanıcı bulunamadı!\n");
        fclose(kullaniciDosya);
        fclose(kitapDosya);
        fclose(oduncDosya);
        return;
    }
    kitapListele();
    int kitapNo;
    printf("Almak istediğiniz kitabın numarasını giriniz >> ");
    scanf("%d", &kitapNo);

    struct Kitap oduncAlinanKitap;
    int kitapBulundu = 0;

    while (fread(&oduncAlinanKitap, sizeof(struct Kitap), 1, kitapDosya) == 1) {
        if (oduncAlinanKitap.kitapNo == kitapNo && oduncAlinanKitap.oduncDurumu == 0) {
            kitapBulundu = 1;
            break;
        }
    }

    if(oduncAlinanKitap.oduncDurumu == 1){
        printf("Kitap ödünç alınmış.");
        kitapBulundu = 1;
    }
    
    if (!kitapBulundu) {
        printf("\nKitap bulunamadı\n");
        fclose(kullaniciDosya);
        fclose(kitapDosya);
        fclose(oduncDosya);
        return;
    }

    fseek(kitapDosya, -(int)sizeof(struct Kitap), SEEK_CUR);
    oduncAlinanKitap.oduncDurumu = 1;
    if (fwrite(&oduncAlinanKitap, sizeof(struct Kitap), 1, kitapDosya) != 1) {
        fprintf(stderr, "Dosya yazma hatası!\n");
    } else {
        fprintf(oduncDosya, "%d %d\n", GeciciKullaniciNo, kitapNo);
        fclose(oduncDosya);
    }

    fclose(kullaniciDosya);
    fclose(kitapDosya);
}


void kitabiGeriGetir(int kullaniciNo, int kitapNo) {
    FILE *dosya;

    dosya = fopen("kitapVeriTabani.txt", "r+b");

    if (dosya == NULL) {
        fprintf(stderr, "Dosya açma hatası!\n");
        return;
    }

    struct Kitap geciciKitap;

    while (fread(&geciciKitap, sizeof(struct Kitap), 1, dosya) == 1) {
        if (geciciKitap.kitapNo == kitapNo && geciciKitap.oduncDurumu == 1) {
            geciciKitap.oduncDurumu = 0;
            fseek(dosya, -(int)sizeof(struct Kitap), SEEK_CUR);
            fwrite(&geciciKitap, sizeof(struct Kitap), 1, dosya);
            printf("Kitap başarıyla geri getirildi.\n");
            fclose(dosya);
            return;
        }
    }

    printf("Kitap bulunamadı veya ödünç alınmamış.\n");
    fclose(dosya);
}

void oduncListele() {
    FILE *oduncDosya, *kullaniciDosya, *kitapDosya;

    oduncDosya = fopen("oduncVeriTabani.txt", "r");
    kullaniciDosya = fopen("kullaniciVeriTabani.txt", "r");
    kitapDosya = fopen("kitapVeriTabani.txt", "r");

    if (oduncDosya == NULL || kullaniciDosya == NULL || kitapDosya == NULL) {
        fprintf(stderr, "Dosya açma hatası!\n");
        return;
    }

    int kullaniciID, kitapID;
    struct Kullanici kullanici;
    struct Kitap kitap;

    printf("%-15s %-30s %-10s %-30s\n", "Kullanıcı ID", "Kullanıcı Adı Soyadı", "Kitap ID", "Kitap Adı");

    while (fscanf(oduncDosya, "%d %d", &kullaniciID, &kitapID) == 2) {

        fseek(kullaniciDosya, 0, SEEK_SET);
        while (fread(&kullanici, sizeof(struct Kullanici), 1, kullaniciDosya) == 1) {
            if (kullanici.kullaniciNo == kullaniciID) {
                break;
            }
        }

        fseek(kitapDosya, 0, SEEK_SET);
        while (fread(&kitap, sizeof(struct Kitap), 1, kitapDosya) == 1) {
            if (kitap.kitapNo == kitapID) {
                break;
            }
        }

        printf("%-15d %-30s %-10d %-30s\n", kullanici.kullaniciNo, kullanici.kullaniciAdiSoyadi, kitap.kitapNo, kitap.kitapIsim);
    }

    fclose(oduncDosya);
    fclose(kullaniciDosya);
    fclose(kitapDosya);
}