#include<iostream>
#include<ctime>
#include <Windows.h>
using namespace std;

class Tasit{
    int hiz,numara,fiyat;
    string model;
    
    public:
        Tasit(int hiz,int numara,int fiyat,string model);
        void goster();
};

Tasit::Tasit(int hiz,int numara,int fiyat,string model){
    this->hiz = hiz;
    this->numara = numara;
    this->fiyat = fiyat;
    this->model = model;
}
void Tasit::goster(){
    cout << "hiz= " << hiz << endl << "numara= " << numara << endl << "fiyat= " << fiyat << endl << "model= " << model << endl << "----------"; 
}

class Sinema{
    public:
        string ad,soyad,filmAdi,tarih;
        void al();
        void goster();
};

void Sinema::al(){
    cout << "ad = ";
    cin >> ad;
    cout << "soyad = ";
    cin >> soyad;
    cout << "filmAdi = ";
    cin >> filmAdi;
    cout << "tarih = ";
    cin >> tarih;
}

void Sinema::goster(){
    cout << "--------------------------" << endl;
    cout << "ad = " << ad << endl;
    cout << "soyad = " << soyad << endl;
    cout << "filmAdi = " << filmAdi << endl;
    cout << "tarih = " << tarih << endl;
    cout << "--------------------------" << endl;
}

class Isci{
    public:
        string ad;
        int maas;
};

void sirala(Isci *isciler,int boyut){

    for(int i=0; i < boyut-1 ; i++){
        int sakla = i;
        for(int j=i+1 ; j < boyut ; j++){
            if (isciler[j].maas > isciler[sakla].maas) sakla = j;
        }
        Isci gecici = isciler[i];
        isciler[i] = isciler[sakla];
        isciler[sakla] = gecici;
    }
}
void isciGoster(Isci *isciler,int boyut){
    for(int i=0; i < boyut ; i++) cout << "ad= " << isciler[i].ad << "--maas= " << isciler[i].maas << endl;
}

class SearchInArr{
    int numara[3] ={1,2,3};
    string ad[3] ={"onur","ahmet","mahmut"};

    public:
        SearchInArr* search(int girdiNUM,string girdiAD);
}C;

SearchInArr* SearchInArr::search(int girdiNUM,string girdiAD){
    SearchInArr *donecek;
    int* A = C.numara;
    for(int i=0; i < 3 ; i++)
        string* B = C.ad;
        for(int j=0; j < 3 ; j++)
            if ()




    return donecek;
}

int main(int argc, char const *argv[])
{
    system("CLS");

    //----------------- 1 --------------------

    /* Tasit Tofas[3] = {Tasit(200,124,400000,"kartal"), Tasit(220,130,500000,"dogan"), Tasit(220,130,235000,"sahin")};
    Tasit *A = Tofas;
    for(int i=0; i<3; i++){
        A->goster();
        A++;
    } */

    //----------------- 2 --------------------

    /* Sinema gosterim[3];
    for(int i=0 ; i < 3; i++){
        gosterim[i].al();
        gosterim[i].goster();
    } */

    //MessageBox(NULL, "Hello, World!", "Message",MB_OKCANCEL);

    //----------------- 3 --------------------

    /* int i = 0;
    Isci isciler[5];
    while(i < 5){
        cout << "Ad= ";
        cin >> isciler[i].ad;
        cout << "Maas= ";
        cin >> isciler[i].maas;
        i++;
    }
    sirala(isciler,5);
    isciGoster(isciler,5); */

    //----------------- 4 --------------------




    return 0;
}
