#include<iostream>
#define fordongu(i,j) for((i)=1;(i)<=(j);(i)++)
using namespace std;
int main(){
	int a,b;
	cout<<"Sayi giriniz....:";
	cin>>b;
	fordongu(a,b) cout<<a<<" nin karesi: "<<a*a<<endl;	
	system("Pause");
	return 0;
}