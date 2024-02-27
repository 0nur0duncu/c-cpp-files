#include<iostream>
#include<cstring>

using namespace std;

void gosterici(double*);
void basvuru(double &);
void faktoriyel(int &);
string& degistir(string &);

class cagirma{
    string a;
    public:
        cagirma(string x){
            a = x;
            cout << "Yapici Fonksiyon!!!" << endl;
        }

        ~cagirma(){
            cout << "Yikici Fonksiyon!!!" << endl;
        }
        string erisim(){
            return a;
        }
};

void basvuruile(cagirma &nesne){
    cout << "Basvuru ile parametre aktarma!!!" << endl;
    cout << "Girilen cumle:" << nesne.erisim() << endl;

}

class test{
    string a;
    public:
        test(string x){
            cout << x << endl;
            a = x;
        }
        string& degistir(test &y){
            y.a = "Yeni Cumle";
            return y.a;
        }

};

int main(int argc, char const *argv[])
{
    system("CLS");

    /////////////////////////////////////////////////////////////
    /* double x = 1;
    gosterici(&x); //adres olarak yollandı.
    cout << "Gosterici ile cagirmadan sonra " << x << endl;
    basvuru(x); //deger olarak yollandi;
    cout << "Basvuru ile cagirmadan sonra " << x << endl; */

    /////////////////////////////////////////////////////////////

    /* int sayi;
    cout << "Faktoriyeli alinacak sayi= ";
    cin >> sayi;
    faktoriyel(sayi);
    cout << "Girilen sayinin faktoriyeli= " << sayi << endl; */

    /////////////////////////////////////////////////////////////

    /* string a = "Ilk cumle";
    cout << "Ilk cumlenin bellekteki yeri:" << &a << endl;
    cout << degistir(a) << endl;
    cout << "Yeni cumlenin bellekteki yeri:" << &degistir(a) << endl;
 */

    /////////////////////////////////////////////////////////////

    /* string cumle;
    cout << "Cumle giriniz...:";
    getline(cin,cumle);

    cagirma x(cumle);
    basvuruile(x); */

    /////////////////////////////////////////////////////////////

    /* test nesne("Ilk cumle!!!");
    cout << nesne.degistir(nesne) << endl; */

    /////////////////////////////////////////////////////////////

    


    return 0;
}

void gosterici(double*a){
    cout << "Gosterici ile cagirma!!!" << endl;
    *a = 5;
}
void basvuru(double &b){
    cout << "Basvuru ile cagirma!!!" << endl;
    b = 10;
}
void faktoriyel(int &b){
    int f =1;
    for(int i = 2; i <= b;i++)
        f *= i;
    b = f;

}
string& degistir(string &cumle){
        cumle = "Yeni cumle";
        return cumle;
}