#include<iostream>
using namespace std;

class test{
    int a;
    public:
        test(int);
        ~test();
        void goruntule();
};

test::test(int a){
    cout << "Yapici fonksiyon calisti\n";
    this->a = a;
}
test::~test(){
    cout << "Yikici fonksiyon calisti\n";
}

void test::goruntule(){
    cout << "a degeri = " << a <<endl;
}
int main(int argc, char const *argv[])
{
    system("CLS");

    test test1(5);
    test1.goruntule();
    return 0;
}
