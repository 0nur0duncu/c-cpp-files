#include<iostream>

using namespace std;

int main(){
    system("CLS");
    //1 ---------------------------------------------
    /* int a,b,c,toplam;
    cout<<"Birinci sayiyi giriniz...: ";
    cin>> a;
    cout<<"Birinci sayiyi giriniz...: ";
    cin>> b;
    cout<<"Birinci sayiyi giriniz...: ";
    cin>> c;
    toplam = a + b + c;
    cout<<"Sonuc -->"<<toplam * toplam<<endl; */
    //2 ---------------------------------------------
    /* int a,b,c;
    cout<<"Birinci sayiyi giriniz...: ";
    cin>> a;
    cout<<"Birinci sayiyi giriniz...: ";
    cin>> b;
    c = (a%5)+(b%3);
    cout<<"Sonuc -->" <<c*c*c<<endl; */
    //3 ---------------------------------------------
    /* int a,b,c,d,ab,cd;
    cout<<"Birinci sayiyi giriniz...: ";
    cin>> a;
    cout<<"Birinci sayiyi giriniz...: ";
    cin>> b;
    cout<<"Birinci sayiyi giriniz...: ";
    cin>> c;
    cout<<"Birinci sayiyi giriniz...: ";
    cin>> d;
    ab = --a + b; 
    cd = ++c * d;
    cout<<"Sonuc -->" <<(ab+cd)%2<<endl; */
    //4 ---------------------------------------------
    /* int a,b;
    cout<<"Birinci sayiyi giriniz...: ";
    cin>> a;
    cout<<"Birinci sayiyi giriniz...: ";
    cin>> b;
    ((a%2)==0 && (b%2)==0) ? cout<<"ikisi de cifttir" : (((a%2)==1 && (b%2==1)) ? cout<<"ikisi de tektir" : cout<<"farkli sonuc");
    cout<<endl; */
    //5 ---------------------------------------------
    /* int a,b,c,enbuyuk,toplam;
    cout<<"Birinci sayiyi giriniz...: ";
    cin>> a;
    cout<<"Birinci sayiyi giriniz...: ";
    cin>> b;
    cout<<"Birinci sayiyi giriniz...: ";
    cin>> c;   
    enbuyuk = (a > b && a > c) ? a : ((b > a && b > c) ? b : c);
    toplam = (a < enbuyuk && b < enbuyuk) ? a+b : ((a < enbuyuk && c < enbuyuk) ? a+c : b + c);
    (toplam > enbuyuk) ? cout<<"Tebrikler" : cout<<"Maalesef";
    cout<<endl; */

    //6 ---------------------------------------------
    /* int yas;
    char a[20],b[20];
    cout<<"Lutfen adinizi giriniz...: ";
    cin>> a;
    cout<<"Lutfen soyadinizi giriniz...: ";
    cin>> b;
    cout<<"Lutfen yasinizi giriniz...: ";
    cin>>yas;

    (yas > 18) ? cout<<"Merhaba "<<a<<" oy kullanabilirsin" : cout<<"Merhaba "<<a<<" yasiniz tutmuyor";
    yas +=3;
    cout<<endl;
    (yas > 18) ? cout<<"Merhaba "<<a<<" oy kullanabilirsin" : cout<<"Merhaba "<<a<<" yasiniz tutmuyor";
    yas +=3;
    cout<<endl;
    (yas > 18) ? cout<<"Merhaba "<<a<<" oy kullanabilirsin" : cout<<"Merhaba "<<a<<" yasiniz tutmuyor"; */

    //7 ---------------------------------------------
    float const PI = 3.14;
    float yaricap,daireAlan,kureHacim;
    cout << "Lutfen yaricapi giriniz...:";
    cin>> yaricap;
    daireAlan = PI * yaricap * yaricap;
    kureHacim = 4 / 3 * PI * yaricap * yaricap * yaricap;
    (daireAlan > kureHacim) ? cout<<"Daire buyuk" : cout<<"Kure buyuk";

    cout<<endl;
    system("PAUSE");
    return 0;
}