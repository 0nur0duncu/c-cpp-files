#include <iostream>
using namespace std;
#include <cstring>

class personeller{
    char ad[20],soyad[20];
    int yas;
    public:
        void arsiv(char *pad,char *psoyad,int yas){
            strcpy(ad,pad);
            strcpy(soyad,psoyad);
            this->yas = yas;
        }
        void goruntele(){
            cout << "Ad = " << ad <<"\nSoyad = " << soyad << "\nYas =" << yas;
        }
}personel[2];

int main(int argc, char const *argv[])
{
    system("CLS");

    personel[0].arsiv("onur","oduncu",25);
    personel[1].arsiv("mehmet","kara",23);
    personel[0].goruntele();
    cout << endl << "---------------------------------------" << endl;
    personel[1].goruntele();

    return 0;
}
