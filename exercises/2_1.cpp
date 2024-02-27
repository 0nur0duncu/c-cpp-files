#include <iostream>
#include<conio.h>

using namespace std;
int main(){
    /* int *a,*b;
    static int PI = 3.14159;
    int c = 5;
    a = (int*)malloc(sizeof(int)*5);
    b = &PI;
    std::cout<<*(--b)<<std::endl; */
    system("CLS");
    double const pi =3.14;
    int r;
    cout<< "Yaricapi giriniz:  ";
    cin>> r;
    cout<<"Alan = "<<pi * r * r<< endl;

    //getch();
    system("PAUSE");
    return 0;
}