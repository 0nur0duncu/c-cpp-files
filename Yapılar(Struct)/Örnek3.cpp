#include<iostream>
using namespace std;
typedef int tamsayi;
typedef char karakter;
typedef char *gosterici;
typedef struct otomobil{
	char *marka;
	int fiyat;
}oto;
#define yazdir cout<<
int main(){
	oto araba;
	tamsayi a=10;
	karakter b='c';
	gosterici c=&b;
	araba.marka="Hundai";
	araba.fiyat=1453;
	yazdir a<<endl;
	yazdir b<<endl;
	yazdir c<<endl;
	yazdir araba.marka<<endl;
	yazdir araba.fiyat<<endl;
	system("Pause");
	return 0;
}