#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
int main(){
	int tutulanSayi=0;
	int tahmin=0;
	time_t saniyeler;
	int tahminSay=0;
	int puan=100;
	saniyeler=time(NULL);
	srand(saniyeler);
	tutulanSayi=rand()%100+1;
	while(tahmin!=-1){
		cout<<"1-100 arasindan bir sayi giriniz...:";
		cin>>tahmin;
		if(tahmin==-1)break;
		if(tahmin<1 || tahmin>100){
			cout<<"Hatali giris:"<<endl;
			continue;
		}
		tahminSay++;
		if(tahmin==tutulanSayi){
			cout<<"tebrikler toplam "<<tahminSay<<" seferde bildiniz!!!"<<endl;
			break;
		}
		else if(tahmin>tutulanSayi){
			cout<<"Daha kucuk bir sayi tahmin ediniz."<<endl;
			puan-=10;

		}
		else{
			cout<<"Daha buyuk bir sayi girmelisin!!!"<<endl;
			puan-=10;
		}
	}
	cout<<"Puanin 100 uzerinden "<<puan<<0?0:puan;
	cout<<endl;
	system("PAUSE");
	return 0;
}