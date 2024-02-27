#include<iostream>
#include<cctype>
using namespace std;
int main(){
	char x[100];
	int i;
	cout<<"Bir harf dizisi giriniz...:";
	gets(x);
	for(i=0;i<strlen(x);i++){
		if(islower(x[i])){
			x[i]=toupper(x[i]);
		}else x[i]=tolower(x[i]);
	}
	puts(x);
	system("PAUSE");
	return 0;
}