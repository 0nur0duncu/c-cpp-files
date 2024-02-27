#include <iostream>
using namespace std;

/**
 * 'Girilen 3 int sayinin carpimi veren metod'
 * @param sayi1,sayi2,sayi3
 * @return carpimSonucu
 * 
*/
int carpma(int,int,int);
/**
 * 'Girilen 3 float sayinin carpimi veren metod'
 * @param sayi1,sayi2,sayi3
 * @return carpimSonucu
 * 
*/
int carpma(float,float,float);

int main(int argc, char const *argv[])
{
    system("CLS");
    int intSayilar[3];
    float floatSayilar[3];

    //---------------------------Soru-1 ---------------------------
/*     for(int i=0 ; i <3 ; i++)
        cin >> intSayilar[i];
    cout << "int sayilarin carpimi = " << carpma(intSayilar[0],intSayilar[1],intSayilar[2]) << endl;
    for(int i=0 ; i <3 ; i++)
        cin >> floatSayilar[i];
    cout << "float sayilarin carpimi = " << carpma(floatSayilar[0],floatSayilar[1],floatSayilar[2]) << endl; */

    //---------------------------Soru-2 ---------------------------

    



    return 0;
}

int carpma(int a,int b,int c){
    return a*b*c;
}

int carpma(float a,float b,float c){
    return a*b*c;
}