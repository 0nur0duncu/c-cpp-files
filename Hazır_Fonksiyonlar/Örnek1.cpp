#include<iostream>
#include<cctype>
using namespace std;
int main(){
	char x[100];
	int i;
	cout<<"Bir dizi girin...:";
	gets(x);
	for(i=0;i<strlen(x);i++){
		x[i]=toupper(x[i]);
	}
	puts(x);
	system("PAUSE");
	return 0;
}