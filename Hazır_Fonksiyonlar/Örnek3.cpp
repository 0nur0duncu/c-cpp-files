#include<iostream>
#include<cstring>
using namespace std;
int main(){
	char string1[]="Kodlab ";
	char string2[]="Kodlab Yayincilik";
	char string3[20];
	strncat(string1,string2,6);//1 e 2 den ilk 6 karakteri ekledi.
	string1[13]='\0';//dizinin sonuna null karakter koydu.
	puts(string1);
	strncpy(string3,string2,6);//3.ye 2 den ilk 6 karakteri kopyaladı.
	string3[6]='\0';//dizinin sonuna null karakter koydu.
	puts(string3);
	system("PAUSE");
	return 0;
}