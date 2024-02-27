#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int secim;
	double i,j;
	cout<<"Lutfen bir islem seciniz..:"<<endl;
	cout<<"1.Karekok alma"<<endl;
	cout<<"2.Us alma"<<endl;
	cout<<"3.e tabaninda logaritma"<<endl;
	cout<<"4.10 tabaninda logaritma"<<endl;
	cout<<"Secilen islem= ";
	cin>>secim;
	switch(secim){
		case 1:cout<<"Karekoku alinacak sayiyi giriniz...: ";
		cin>>i;
		cout<<sqrt(i)<<endl;break;
		case 2:cout<<"Taban giriniz...: ";
		cin>>i;
		cout<<"Us giriniz...: ";
		cin>>j;
		cout<<pow(i,j)<<endl;break;
		case 3:cout<<"sayiyi giriniz...: ";
		cin>>i;
		cout<<log(i)<<endl;break;
		case 4:cout<<"Sayiyi giriniz...: ";
		cin>>i;
		cout<<log10(i)<<endl;break;
		default:cout<<"Hatali secim!!!";break;
	}
	system("PAUSE");
	return 0;
}