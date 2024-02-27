#include<iostream>
using namespace std;
int main(){
	char karakter1='a',karakter2='b';
	char *const ptr=&karakter1;
	//ptr=&karakter2; //yanlis kullanim
	*ptr='c';//adres değişemez ancak içerisindeki deger degisir.
	system("Pause");
	return 0;
}