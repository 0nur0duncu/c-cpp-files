#include<iostream>
#include<cmath>
using namespace std;
int main(){
	double sayi;
	cout<<"Sayi giriniz...:";
	cin>>sayi;
	cout<<"Girilen sayidan kucuk,en buyuk tamsayi:"<<floor(sayi)<<endl;
	cout<<"Girilen sayidan buyuk,en kucuk tamsayi:"<<ceil(sayi)<<endl;
	system("PAUSE");
	return 0;	
}