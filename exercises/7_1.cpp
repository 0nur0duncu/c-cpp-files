#include<iostream>
#include<math.h>

using namespace std;

int toplam(int sayilar[],int uzunluk);
double eskenarAlan(int yukseklik);
int ebob(int sayi1,int sayi2);
int ekok(int sayi1,int sayi2);
int mukemmel();
int permutasyon(int n, int r);

int main(int argc, char const *argv[])
{
    system("CLS");

    //----------------------- 1 --------------------------

    /* int sayilar[10];
    for(int i=0; i<10; i++){
        cout<< i + 1 <<". sayi = ";
        cin>> sayilar[i]; 
    }
    cout<< "Sayilarin toplami = "<< toplam(sayilar,10) << endl; */

    //----------------------- 2 --------------------------

    /* int yukseklik;

    cout << "Ucgenin yuksekligini giriniz...:";
    cin >> yukseklik ; 
    cout << "Eskenar ucgenin alani = "<< eskenarAlan(yukseklik); */

    //----------------------- 3 --------------------------

    /* int sayi1,sayi2;
    cout << "Birinci sayiyi giriniz...:";
    cin >> sayi1 ;
    cout << "Birinci sayiyi giriniz...:";
    cin >> sayi2 ;
    cout << "Sayilarin ebobu = " << ebob(sayi1, sayi2); */

    //----------------------- 4 --------------------------

    /* int sayi1,sayi2;
    cout << "Birinci sayiyi giriniz...:";
    cin >> sayi1 ;
    cout << "Birinci sayiyi giriniz...:";
    cin >> sayi2 ;
    cout << "Sayilarin ekoku = " << ekok(sayi1, sayi2); */

    //----------------------- 5 --------------------------

    /* mukemmel(); */

    //----------------------- 6 --------------------------

    int n, r;
    cout << "n sayisini giriniz...:";
    cin >> n ;
    cout << "r sayisini giriniz...:";
    cin >> r ;
    cout << "Sayilarin permutasyonu = " << permutasyon(n, r);

    cout << endl;
    system("PAUSE");
    return 0;

}


int toplam(int sayilar[],int uzunluk){

    int toplam = 0;
    for(int i=0; i< uzunluk; i++){
        toplam += sayilar[i];
    }

    return toplam;
}

double eskenarAlan(int yukseklik){
    double alan;
    alan= (yukseklik * yukseklik) / pow(3,0.5);
    return alan;
}

int ebob(int sayi1,int sayi2){

    int kucuk = sayi1 > sayi2 ? sayi2 : sayi1;
    int buyuk = sayi1 > sayi2 ? sayi1 : sayi2;

    while(kucuk-- <= buyuk)
        if (buyuk % kucuk == 0) break;
    return kucuk;
}

int ekok(int sayi1,int sayi2){
    int kucuk = sayi1 > sayi2 ? sayi2 : sayi1;
    int buyuk = sayi1 > sayi2 ? sayi1 : sayi2,i = buyuk;

    for( ;;i++)
        if (i % buyuk == 0 && i % kucuk == 0) break;
    return i;
}

int mukemmel(){
    int toplam;
    for ( int i = 1 ; i <= 100 ; i++){
        for (int j = i-1; j >= 1; j--) 
            if(i % j ==0) toplam += j;
        if (i == toplam) cout<<i<<endl;
        toplam = 0;
    }

}

int permutasyon(int n, int r){
    int sonuc = 1;
    for (int i = n ; i >r ; i--)
        sonuc *= i;
    return sonuc;
}