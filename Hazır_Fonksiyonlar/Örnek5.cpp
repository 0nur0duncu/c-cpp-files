#include<iostream>
#include<cstring>
using namespace std;
int main(){
	char dizi1[]="Muhammed MASTAR";
	char dizi2[]="Suha Eris";
	char *dizi3,*b,a;
	dizi3=strstr(dizi1,"ed");//2.diziyi birincide arar.Geri dönüş olarakta ilk dizide ikinci dizi ilk nerede görülüyorsa
	//oradan itibaren dizinin devamını döndürür.\0 karaktere kadar yazdırır.
	puts(dizi3);
	cout<<"Bir karakter giriniz....:";
	cin>>a;
	b=strchr(dizi2,a);//yazdığımız karakteri dizide arar ve bulunca o da dahil yazdırmaya başlar.
	if(b==NULL) cout<<"Aranan karakter dizide yok."<<endl;
	else cout<<b<<endl;
	system("PAUSE");
	return 0;
}