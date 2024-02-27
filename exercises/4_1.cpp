#include<iostream>
#include<locale.h>

using namespace std;
int main(int argc, char const *argv[])
{
    setlocale(LC_ALL,"Turkish");
    //----------------- 1 -----------------------------
/*  int sayi1,sayi2,kucuk;
    cout<< "Birinci sayiyi giriniz....:";
    cin>> sayi1;
    cout<< "Ikinci sayiyi giriniz....:";
    cin>> sayi2;

    kucuk = sayi1 > sayi2 ? sayi2 : sayi1;

    (kucuk % 2 == 0) ? cout<< "Cift" : cout<< "Tek";
    cout<<endl; */

    //-------------------2-----------------------------

    /* short sayi;
    cout<< "Bir sayi giriniz.....:";
    cin>> sayi;
    switch (sayi)
    {
    case 1:
        cout << "İlkbahar";
        break;
    case 2:
        cout << "Yaz";
        break;
    case 3:
        cout << "Sonbahar";
        break;
    case 4:
        cout << "Kis";
        break;
    default:
    cout << "Invalid number";
        break;
    } */

    //-------------------3----------------------------------

    /* int sayi;
    cout<<"Lutfen bir sayi giriniz...:";
    cin>> sayi;
    (sayi /100 * 35 >1000) ? cout<< "Sayi 1000 den buyuktur." : cout<< "Sayi 1000 den kucuktur."; */

    //---------------------4--------------------------------
    /* int sayi;
    cout<< "Bir sayi giriniz.....:";
    cin>> sayi;
    switch (sayi)
    {
    case 1:
        cout << "Bir";
        break;
    case 2:
        cout << "İki";
        break;
    case 3:
        cout << "Üç";
        break;
    case 4:
        cout << "Dört";
        break;
    default:
    cout << "Invalid number";
        break;
    } */

    //---------------------5--------------------------------

    /* char girdi;
    cout<< "Bir karakter giriniz...:";
    cin>> girdi;
    if (girdi =='1' || girdi == '2' || girdi == '3') cout<<"sayi";
    else if (girdi =='a' || girdi == 's' || girdi == 'd') cout<<"Char";
    else if (girdi =='-' || girdi == '+' || girdi == '/') cout<<"Ozel Karakter"; */

    //---------------------6--------------------------------

    char girdi,sifre = '5';
    cout<< "Bir sifre giriniz...:";
    cin>> girdi;

    if (sifre == girdi) cout<< "Hosgeldiniz";
    else{
        cout << "2 Hakkiniz Kaldi"<<endl;
        cout<< "Bir sifre giriniz...:";
        cin>> girdi;
        if (sifre == girdi) cout<< "Hosgeldiniz";
        else{
            cout << "1 Hakkiniz Kaldi"<<endl;
            cout<< "Bir sifre giriniz...:";
            cin>> girdi;
            if (sifre == girdi) cout<< "Hosgeldiniz";
            else{
                cout<< "Bir sifre giriniz...:"<<endl;
                cin>> girdi;
                if (sifre == girdi) cout<< "Hosgeldiniz";
                else{
                    cout<< "Hakkiniz bitti";
                }
            }
        }
    }

    cout <<endl;
    system("PAUSE");
    return 0;
}

