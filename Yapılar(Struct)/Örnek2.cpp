#include<iostream>
using namespace std;
	struct calisan{
		char *ad,*soyad;
		int yas;
	};//x={"Muhammed","MASTAR",22};//1.yöntem
	//struct calisan x={"Muhammed","MASTAR",22};//2.yöntem
int main(){
	//calisan x={"Muhammed","MASTAR",22};//3.yöntem
	/*x.ad="Muhammed";
	x.soyad="MASTAR";
	x.yas=22;*///4.yöntem
	cout<<"calisanin adi: "<<x.ad<<endl;
	cout<<"calisanin soyadi: "<<x.soyad<<endl;
	cout<<"calisanin yasi: "<<x.yas<<endl;
	system("Pause");
	return 0;
}