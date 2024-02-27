#include<iostream>
using namespace std;
int main(){
	float sayi1=1.0,sayi2=2.0;
	const float *const x=&sayi1;//hem sayi hem de adres sabit oldugu icin hicbir degisiklik yapilamaz.
	//*x=7;//hatali kullanim
	//x=sayi2;//hatali kullanim
	system("Pause");
	return 0;
}