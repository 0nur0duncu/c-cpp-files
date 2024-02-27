#include<iostream>
using namespace std;
int main(){
	int i[5]={1,2,3,4,5};
	int *ptr;
	ptr=i;
	cout<<"*ptr nin ilk degeri= "<<*ptr<<endl;//1
	cout<<"ptr nin ilk degeri= "<<ptr<<endl;// 0x78fe00
	
	cout<<"++*ptr nin degeri= "<<++*ptr<<endl;//2
	cout<<"ptr nin yeni degeri= "<<ptr<<endl;// 0x78fe00
	
	cout<<"*++ptr nin degeri= "<<*++ptr<<endl;//2
	cout<<"ptr nin yeni degeri= "<<ptr<<endl;// 0x78fe04
	
	cout<<"*ptr++ nin degeri= "<<*ptr++<<endl;//2
	cout<<"ptr nin yeni degeri= "<<ptr<<endl;// 0x78fe08
	
	cout<<"*ptr nin son degeri= "<<*ptr<<endl;//3
	cout<<"ptr nin yeni degeri= "<<ptr<<endl;// 0x78fe08
	
	//dizilerde belirtilen elemanları da degistiriyor.
	system("PAUSE");
	return 0;
}