#include<iostream>
using namespace std;
int main(){
	char *ptr,isim[20];
	int i=0;
	cout<<"isim giriniz...:";
	gets(isim);
	ptr=isim;
	while(*(ptr+i) !=NULL){
		cout<<*(ptr+i);
		i++;
	}
	cout<<endl;
	system("Pause");
	return 0;
}