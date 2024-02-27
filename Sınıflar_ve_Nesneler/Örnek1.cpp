#include<iostream>
using namespace std;
class dikdortgen{
	public:
		int kisa_kenar;
		int uzun_kenar;
		
		int alan(){
			return kisa_kenar*uzun_kenar;
		}
		int cevre(){
			return 2*(uzun_kenar+kisa_kenar);
		}
}x;
int main(){
	cout<<"Kisa kenari giriniz...:";
	cin>>x.kisa_kenar;
	cout<<"Uzun kenari giriniz...:";
	cin>>x.uzun_kenar;
	cout<<"Dikdortgenin Alani: "<<x.alan()<<endl;
	cout<<"Dikdortgenin Cevre: "<<x.cevre()<<endl;
	system("PAUSE");
	return 0;
}