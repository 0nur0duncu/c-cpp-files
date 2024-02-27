#include<iostream>
using namespace std;
int main(){
	int x=5,y=10;
	const int *a=&x;
	//*a=20;//bu kullanım yanlıştır çünkü sabitin değeri değişemez .
	a=&y;//fakat adresi değiştirilebilir.
	system("Pause");
	return 0;
}