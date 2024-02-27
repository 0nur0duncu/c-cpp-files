#include<iostream>
#include<cstring>
using namespace std;

class sayilar{
    mutable int sayi;
    public: 
        int b,c;
        string a;
        sayilar(string,int,int);
        void goster();
};

void sayilar::goster(){
    cout << "A =" << a << "\tB =" << b << "\tC=" << c;
}
sayilar::sayilar(string a,int b,int c){
    this->a = a;
    this->b = b;
    this->c = c;
    sayi =0;
}

int main(int argc, char const *argv[])
{
    system("CLS");
    sayilar sayi("onur",7,9);
    sayi.goster();

    return 0;
}
