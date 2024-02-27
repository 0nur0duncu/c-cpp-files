#include<iostream>
#include<string>
using namespace std;
class isciler{
	string ad,soyad;
	int saat_ucreti,calistigi_saat;
	double aylik_maas;
	public:
		void bilgi_gir(){
			cout<<"Iscinin adini gir...:";
			cin>>ad;
			cout<<"Iscinin soyadini gir...:";
			cin>>soyad;
			cout<<"Iscinin 1 saate aldigi ucreti giriniz...:";
			cin>>saat_ucreti;
			cout<<"Iscinin 1 ayda kac saat calistigini giriniz...:";
			cin>>calistigi_saat;
		}
		double maas(){
			return aylik_maas=saat_ucreti*calistigi_saat;
		}
		void goster(){
			cout<<"İscinin adi: "<<ad<<endl;
			cout<<"İscinin soyadi: "<<soyad<<endl;
			cout<<"İscinin maasi: "<<maas()<<endl;
			yorum(maas());
		}
		void yorum(double aylik_maas){
			if(aylik_maas>800){
				cout<<"Maasi asgari ucretten yuksek"<<endl;
		}
		else{
			cout<<"Maasi asgari ucretten dusuk"<<endl;
		}
}
}isci1,isci2;
int main(){
	isci1.bilgi_gir();
	cout<<"----------------------------"<<endl;
	isci2.bilgi_gir();
	cout<<"----------------------------"<<endl;
	cout<<"İscilerin bilgileri---------";
	isci1.goster();
	cout<<"----------------------------"<<endl;
	isci2.goster();
	system("PAUSE");
	return 0;

}