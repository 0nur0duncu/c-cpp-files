#include<iostream>
using namespace std;
int main(){
	int a=5;
	int *ptr;
	ptr=&a;
	cout<<*ptr<<" degiskeninin ramdaki adresi= "<<ptr<<endl;
	system("PAUSE");
	return 0;
}
