#include<iostream>
using namespace std;
class personel{
	int yas;
	public:
		void gir(int Yas){
			yas=Yas;
		}
		void yasyaz(){
			cout<<yas;
		}
}a;
int main(){
	int x;
	cout<<"Personelin yasini giriniz...:";
	cin>>x;
	a.gir(x);
	cout<<"Personelin Yasi :";
	a.yasyaz();
	cout<<endl;
	system("PAUSE");
	return 0;
}