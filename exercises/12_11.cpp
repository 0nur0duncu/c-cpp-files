#include<iostream>
using namespace std;

class yapici_yikici{
    char harf;
    int sayac;
    public:
        yapici_yikici(){
            sayac++;
            cout << "\nYapici Fonksiyon Cagrildi.";
        }
        ~yapici_yikici(){
            sayac--;
            cout << "\nYikici Fonksiyon Cagrildi.";
        }
        int say(){
            return sayac;
        }
};

int main(int argc, char const *argv[])
{
    system("CLS");

    cout << "\nBolum 1 basliyor...\n";
    yapici_yikici nesne1,nesne2,nesne3;

    cout << "\nBolum 2 basliyor...\n";
    yapici_yikici nesne4,nesne5;

    cout << "\nBolum 2 bitiyor...\n";
    cout << "\nBolum 1 bitiyor...\n";
    return 0;
}
