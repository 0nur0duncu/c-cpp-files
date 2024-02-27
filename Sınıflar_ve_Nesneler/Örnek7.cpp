#include<iostream>
using namespace std;
class ConstOrnek{
	int sayi;// eğer mutable int sayi; yazsaydık 2.durumda hata vermeyecekti.
	public:
	    ConstOrnek(){
	    	sayi=0;
			}
		void SayiAta(int x){
			sayi=x;
			}
		int dondur() const{
			return sayi;
		}
};
int main(){
	const ConstOrnek test;//nesne const olarak tanimlandı.
	ConstOrnek test2;//nesne const olmadan tanımlandı.
	test.dondur();//nesne const-fonksiyon const(hata yok!!!)
	//test.SayiAta(5);//nesne const-fonksiyon const değil(hata!!!)
	test2.dondur();//nesne const değil-fonksiyon const(hata yok!!!)
	test2.SayiAta(5);//nesne const değil-fonksiyon const değil(hata yok!!!)
	system("PAUSE");
	return 0;
}