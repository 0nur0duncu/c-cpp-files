#include<iostream>
using namespace std;

class Kamyon;
class Araba{
    int kisi_sayisi,hiz;
    public:
        Araba(int y,int h){
            kisi_sayisi = y;
            hiz = h;
        }
    int arkadaslik(Kamyon k);
};
class Kamyon{
    int tonaj,hiz;
    public:
        Kamyon(int a,int h){
            tonaj = a;
            hiz = h;
        }
        friend int Araba::arkadaslik(Kamyon k);
};
int Araba::arkadaslik(Kamyon k){
    return hiz - k.hiz;
}

int main(int argc, char const *argv[])
{
    system("CLS");
    int m;
    Araba araba1(2,225);
    Araba araba2(4,85);
    Kamyon kamyon3(3000,75);
    Kamyon kamyon4(32000,85);

    cout << "Araba1 ve Kamyon3:\n";
    m = araba1.arkadaslik(kamyon3);

    if(m<0)
        cout << "Kamyon daha hizli";
    else if(m==0)
        cout << "Kamyon ile Arabanin hizlari esit.\n";
    else
        cout << "Araba daha hizli.\n";
    
    cout << "\nAraba2 ve kamyon4 :\n";
    m = araba2.arkadaslik(kamyon4);

    if(m<0)
        cout << "Kamyon daha hizli";
    else if(m==0)
        cout << "Kamyon ile Arabanin hizlari esit.\n";
    else
        cout << "Araba daha hizli.\n";

    return 0;
}