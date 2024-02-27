#include<iostream>

using namespace std;

struct bilgi
{
    char ad[15],soyad[15];
    int yas,numara;
};
struct isciler
{
    char ad[15],soyad[15];
    int yas,maas;
}isci[10];

struct size{
    int a;
    double b;
    float c;

}nesne;

struct ort
{
    char ad[20], soyad[20];
    float vize,final;

}ogr[3];

struct notlar{
    double notlar;
}cpp[5];

int main(int argc, char const *argv[])
{
    system("CLS");
    //------------------------1-------------------------
    /* struct bilgi kisi1;
    cout<<"Lutfen sirasiyla ad,soyad,yas ve numara bilgilerini giriniz...:";
    cin>>kisi1.ad>>kisi1.soyad>>kisi1.yas>>kisi1.numara;
    cout<<kisi1.ad<<" "<<kisi1.soyad<<" "<<kisi1.yas<<" "<<kisi1.numara<<endl;  */

    //------------------------2-------------------------

    /* for(int i=0;i < 10 ; i++){
        cout<<"Lutfen sirasiyla ad,soyad,yas ve maas bilgilerini giriniz...:";
        cin>>isci[i].ad>>isci[i].soyad>>isci[i].yas>>isci[i].maas;
    }
    cout<<"Maas Bilgileri";
    cout<<"------------------------------";
    for(int i=0;i < 10 ; i++){ 
        cout << isci[i].maas * 61.051 / 100 <<endl;
    } */
    
    //------------------------3-------------------------

    /* cout<< (sizeof(nesne.a) + sizeof(nesne.b) + sizeof(nesne.c)) << endl;
    cout<<sizeof(nesne);
 */

    //------------------------4-------------------------

    /* for(int i=0; i < 3; i++){
        cout << " Lutfen sirasiyla ad - soyad - vize - final notlarini giriniz" << endl;
        cin >> ogr[i].ad >> ogr[i].soyad >> ogr[i].vize >> ogr[i].final ;
    }

    for(int i=0; i < 3; i++){
        float ortalama = ogr[i].vize *0.3 + ogr[i].final * 0.7;
        if (ortalama > 60) cout << ogr[i].ad << " "<< ogr[i].soyad << "--> Gecti";
        else cout << ogr[i].ad << " "<< ogr[i].soyad << "--> Kaldi";
        cout << endl;
    } */
    
    //------------------------5-------------------------

    for( int i = 0; i < 5; i++ ){
        cout << i+1 << ". ogrenci notu = ";
        cin >> cpp[i].notlar;
    }

    for ( int i = 0 ; i < 4; i++){

        int sakla = i;
        for(int j = i+1; j < 5 ; j++) 
            if (cpp[j].notlar > cpp[sakla].notlar) sakla = j;

        double gecici = cpp[i].notlar;
        cpp[i].notlar = cpp[sakla].notlar;
        cpp[sakla].notlar = gecici;
    }

    for( int i = 0; i < 5; i++ ){
        cout << cpp[i].notlar << "--";
    }


    cout<<endl;
    system("PAUSE");
    return 0;
}
