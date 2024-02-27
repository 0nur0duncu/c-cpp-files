#include<iostream>
#include<cctype>
#include <cstring>
//#include<string>
#include <math.h>
//#include <cmath>
#include<conio.h>
#include<ctime>
#include<cstdlib>
using namespace std;

int main(){
    system("CLS");

    /* int sayi;
    cout << "bir karakter giriniz:";
    cin >> sayi;

    cout << isalpha(sayi) << endl;
    cout << isdigit(sayi) << endl;
    cout << isalnum(sayi) << endl;
    cout << islower(sayi) << endl;
    cout << isupper(sayi) << endl;
    cout << isgraph(sayi) << endl;
    cout << isprint(sayi) << endl;
    cout << isxdigit(sayi) << endl;
    cout << isspace(sayi) << endl;
    cout << iscntrl(sayi) << endl;
    cout << tolower(sayi) << endl;
    cout << isupper(sayi) << endl; */

    /* char ad[15];
    int i = 0;
    cout << "Adiniz ..:";
    cin >> ad;
    cout << strlen(ad) << endl;
    while(ad[i] != '\0'){
        ad[i] = toupper(ad[i]);
        i++;
    }
    puts(ad); */

    /* char ad[7];
    cout << "isim : " ;
    //cin >> ad;
    gets(ad);
    //ad[5] = '\0';
    ad[6] = 'l';

    cout << ad; */

    /* char a[] = "onur asdfasdfas";
    cout << strchr(a,'s'); */

    //cout << sqrt(25);


    //zaman ve tarih fonksiyonları

    /* time_t x;
    struct tm *zaman;
    time(&x);
    zaman = localtime(&x);
    cout << "Anlik zaman - tarih : "<< asctime(zaman); */
    
    int tutulanSayi = 0;
    int tahmin = 0;
    time_t saniyeler;
    int TahminSay  = 0 ;
    int puan = 100;

    saniyeler = time (NULL);
    srand(saniyeler);
    tutulanSayi = rand() % 100 +1;
    while(tahmin != -1){
        cout << "1 ile 100 arasinda sayi giriniz..: ";
        cin >> tahmin;
        TahminSay++;
    }
    cout << "puaniniz = " << puan - TahminSay * 5 +5;
    cout << saniyeler;

    cout << endl;
    system("PAUSE");
    return 0;
}