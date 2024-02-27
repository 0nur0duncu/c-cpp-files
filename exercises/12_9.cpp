#include<iostream>
using namespace std;

class ornek{
    int sayi;
    public:
        friend int sayi_fonk(ornek deneme);
        ornek(){
            sayi = 12;
        }
}a;

int sayi_fonk(ornek deneme){
    return a.sayi;
}
int main(int argc, char const *argv[])
{
    system("CLS");
    cout << sayi_fonk(a) << endl;
    return 0;
}
