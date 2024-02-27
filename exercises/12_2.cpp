#include<iostream>
using namespace std;

class goster{

    int Sayi;
    public:
        void atama_yap(int sayi){
            Sayi = sayi;
        }
        void sayiyiGoster(){
            cout << Sayi <<endl;
        }
}x,y;

int main(int argc, char const *argv[])
{
    x.atama_yap(10);
    y.atama_yap(20);
    x.sayiyiGoster();
    y.sayiyiGoster();
    return 0;
}
