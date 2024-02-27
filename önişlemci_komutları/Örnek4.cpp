#include<iostream>
#define BAY
#define BAYAN
int main(){
	#if BAY && BAYAN //hata mesajı verecektir.
	#error Hem bay hem de bayan aynı anda olamaz.
	#endif
	system("PAUSE");
	return 0;
}