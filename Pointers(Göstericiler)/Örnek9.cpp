#include<iostream>
using namespace std;
int main(){
	int sayi=8;
	char harf='c';
	void *deger;
	deger=&sayi;
	cout<<"Sayi: "<<*(int*)deger<<endl;
	deger=&harf;
	cout<<"Harf: "<<*(char*)deger<<endl;
	system("Pause");
	return 0;
}