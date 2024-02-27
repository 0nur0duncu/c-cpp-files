#include<iostream>
using namespace std;
class sayilar{
	public:
		int a,b,c;
		sayilar(){
			a=1,b=4,c=15;//böyle bir atama şeklide vardır
		}
}sayi;
int main(){
	cout<<"A degeri: "<<sayi.a<<endl;
	cout<<"B degeri: "<<sayi.b<<endl;
	cout<<"C degeri: "<<sayi.c<<endl;
	system("PAUSE");
	return 0;
}