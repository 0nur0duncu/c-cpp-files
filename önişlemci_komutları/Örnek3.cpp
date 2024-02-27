#include<iostream>
#include<math.h>
#define kareal(a) (a*a)
#define toplama(a,b) (a+b)
#define carpma(a,b) (a*b)
#define bolme(a,b) (a/b)
using namespace std;
int main(){
	float  a=3.0,b=4.0;
	cout<<"kareal(2) = "<<kareal(2)<<endl;
	cout<<"a degeri = "<<a<<"  ---- b degeri = "<<b<<endl;
	cout<<"toplama = "<<toplama(a,b)<<endl;
	cout<<"carpma = "<<carpma(a,b)<<endl;
	cout<<"bolme = "<<bolme(a,b)<<endl;
	system("Pause");
	return 0;
}