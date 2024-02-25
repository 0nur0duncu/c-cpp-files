#include "Dizi.cpp"
int main(int argc, char* argv[])
{
    for (int i = 5; i < 10; ++i) {
    Dizi a(i);
    a += i;
    Dizi b = a*(i-1);//a*i-1 hata verir
    cout << b;
    }
    return 0;
}
