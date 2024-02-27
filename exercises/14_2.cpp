#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class Otel{
    string *musteri_adi[100],*soyad[100];
    int toplam, sayac1, sayac2;

    enum statu{
        bos,dolu
    }odalar[45];

    public:
        Otel();
        void oda_rezarvasyonu();
        void oda_isletmesi();
        void oda_bosaltma();
        void musterilerin_sayisi();
        void yatak_odasi_raporu();
        void seminer_odasi_raporu();
        void gelir(); 
};
Otel::Otel(){
    sayac1 = 0;
    sayac2 = 0;
    oda_isletmesi();
}

void Otel::oda_isletmesi(){

    for(int a=1 ; a < 46 ; a++)
        odalar[a] = bos;
        int sayi;
        do{

            cout << "\n\t\t--- KODLAB OTEL ---\n" << endl;
            cout << "\n\t\t1. Oda Rezervasyonu\n" << endl;
            cout << "\n\t\t2. Oda Boşaltma\n" << endl;
            cout << "\n\t\t3. Dolu Oda Sayisi\n" << endl;
            cout << "\n\t\t4. Yatak Odasi Raporu\n" << endl;
            cout << "\n\t\t5. Seminer Odasi Raporu\n" << endl;
            cout << "\n\t\t6. Gunluk Toplam Gelir\n" << endl;
            cout << "\n\t\t7. Cikis Yap\n" << endl;
            cout << "Seciminizin numarasini giriniz..: ";
            cin >> sayi;

            switch(sayi){

                case 1:
                    oda_rezarvasyonu();
                    break;
                case 2:
                    oda_bosaltma();
                    break;
                case 3:
                    musterilerin_sayisi();
                    break;
                case 4:
                    yatak_odasi_raporu();
                    break;
                case 5:
                    seminer_odasi_raporu();
                    break;
                case 6:
                    gelir();
                    break;
                case 7:
                    exit(1);
                default:
                    cout << "Yanlis bir deger girdiniz Lutfen dogru deger giriniz..." << endl;
            }
        }while(sayi != 7);
}

void Otel::oda_rezarvasyonu(){

    int sayi, x2 ,i = 1, j=6, k=16;
    string ad,o_ad;
}