#include<iostream>
#include<cstring>
using namespace std;
int main(){
	char dizi[100];
	cout<<"Bir cumle giriniz...:";
	gets(dizi);
	strrev(dizi);
	cout<<endl;
	cout<<"Cumlenin tersi  = ";
	puts(dizi);
	cout<<endl;
	system("PAUSE");
	return 0;
}