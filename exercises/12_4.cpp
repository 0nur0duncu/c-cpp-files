#include<iostream>
#include<time.h>
using namespace std;

class ConstOrnek{
    public:
        int sayi;
        ConstOrnek(){
            sayi = 0;
        }
        void SayiAta(int x){
            sayi = x;
        }
        int dondur() const{
            return sayi;
        }
};

int main(int argc, char const *argv[])
{
    system("CLS");

    const ConstOrnek test;
    ConstOrnek test2;

    test.dondur();
    //test.SayiAta(5);

    test2.dondur();
    test2.SayiAta(5);

    return 0;
}
