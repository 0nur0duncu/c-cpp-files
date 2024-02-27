#include <iostream>

using namespace std;

void toplam(int,int);
void toplam(float,float);

class yapici {
    int a, b;
public:
    yapici() {
        a = b = 5;
        cout << "a = " << a << "\nb = " << b << endl;
    }
    yapici(int x, int y) {
        a = x;
        b = y;
        cout << "a = " << a << "\nb = " << b << endl;
    }
};

int main(int argc, char const *argv[]) {
    system("CLS");

    toplam(5,7);
    toplam(5.2f,5.7f);
    toplam(5.2,7);

    yapici obj1;
    yapici obj2(5,7);

    return 0;
}

void toplam(int a=5,int b=5){
    cout << a << " + " << b << " = " << a + b << endl;
}
void toplam(float a=2.4f,float b=2.3f){
    cout << a << " + " << b << " = " << a + b << endl;
}
