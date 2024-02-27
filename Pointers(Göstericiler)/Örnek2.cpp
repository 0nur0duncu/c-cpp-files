#include<iostream>
using namespace std;
int main(){
	int girilen;
	int *ptr;
	cout<<"lütfen bir ssayi giriniz...:"<<endl;
	cin>>girilen;
	ptr=&girilen;
	cout<<"Girdiginiz "<<*ptr<<" sayisinin ramdeki adresi= "<<ptr<<endl;
	
	system("Pause");
	return 0;
}