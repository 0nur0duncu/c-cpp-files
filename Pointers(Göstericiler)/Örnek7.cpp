#include<iostream>
using namespace std;
void referansile1(int *x){
	*x=20;
	cout<<"deger ile cagirma!!"<<endl;
}
void *referansile2(int x){
	x=20;
	return &x;
	
}
//pointerlar ile yaptığımız fonksiyon işlemlerinde eğer gönderdiğimiz adres ise o adresteki değer değişir.
int main(){
	int a=10,b=10;
	cout<<"degiskenin ilk degeri:"<<a<<endl;
	referansile1(&a);
	cout<<"degiskenin ikinci degeri:"<<a<<endl;
	referansile1(&b);
	cout<<"degiskenin ucuncu degeri:"<<b<<endl;//adres *x şeklinde sayı olarak döndü.
	system("Pause");
	return 0;
	}