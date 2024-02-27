#include<iostream>
#include<string>
using namespace std;
class personeller{
	string personel_adi,personel_soyadi;
	int yas;
	public:
		void arsiv(string padi,string psoyadi,int sayi){
			personel_adi=padi;
			personel_soyadi=psoyadi;
			yas=sayi;
		}
		void goruntule(){
			cout<<"Personel Adi: "<<personel_adi<<endl;
			cout<<"Personel Soyadi: "<<personel_soyadi<<endl;
			cout<<"Personelin Yasi: "<<yas<<endl;
		}
}pers1,pers2,pers3;
int main(){
	pers1.arsiv("Muhammed","Mastar",22);
	pers2.arsiv("Suha","eris",21);
	pers3.arsiv("Tahir","Vural",20);
	
	pers1.goruntule();
	pers2.goruntule();
	pers3.goruntule();
	system("Pause");
	return 0;
}