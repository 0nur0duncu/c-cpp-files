#include<iostream>
#include "Ogrenci.cpp"

using namespace std;

int main(int argc, char const *argv[])
{
    Urun urun1("Klavye", 149.99);
    Urun urun2("Fare", 300.0);
    AlisVerisSepeti sepet;
    sepet.urun_ekle(urun1, 5);
    sepet.urun_ekle(urun2, 2);
    sepet.urun_ekle(Urun("34\" ekran", 7999.0), 1);
    double tutar = sepet.toplam_tutar_hesapla();
    cout << "Toplam tutar: " << tutar << endl;
    // AlisVerisSepeti sınıfı tamamlandığında ekrana 9348.95 yazması gerekir.
    return 0;
}
