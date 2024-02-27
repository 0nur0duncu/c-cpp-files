#include<iostream>
using namespace std;
typedef struct calisan{
	char *ad,*soyad,*gorevi;
	int calisanno;
}eleman;
int main(){
	eleman a[]={"Suha","Eris","Programci",1,"Muhammed","MASTAR","Programci",2,"Tahir","Vural","Programci",3};
	cout<<"Calisanlar Listesi"<<endl;
	cout<<"AD: SOYAD: GOREVi: "<<endl;
	for(int i=0;i<3;i++){
		cout<<a[i].ad<<" "<<a[i].soyad<<" "<<a[i].gorevi<<" "<<a[i].calisanno<<endl;
	}
	system("Pause");
	return 0;
}