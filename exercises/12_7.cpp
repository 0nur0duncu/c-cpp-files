#include<iostream>
using namespace std;

class nesneden_nesneye{
    int a;
    public:
        void atama_yap(int);
        void goruntule();
};

void nesneden_nesneye::atama_yap(int a){
    this->a = a;
}
void nesneden_nesneye::goruntule(){
    cout << "a nin degeri = " << a <<endl;
}
int main(int argc, char const *argv[])
{
    system("CLS");

    nesneden_nesneye nesne1,nesne2;
    nesne1.atama_yap(5);
    nesne2 = nesne1;

    nesne1.goruntule();
    nesne2.goruntule();
    return 0;
}
