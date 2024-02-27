#include<iostream>
#include<string>
using namespace std;
class insanlar{
	string ad,soyad;
	int yas;
	public:
		insanlar(string a,string b,int c){//global olmadığı için sanki fonksiyon gibi kullandık.
			ad=a;
			soyad=b;
			yas=c;
		}
		void goster(){
			cout<<"Ad: "<<ad<<endl;
			cout<<"Soyad: "<<soyad<<endl;
			cout<<"Yas: "<<yas<<endl;
			cout<<"------------------"<<endl;
		}
};
int main(){
	insanlar insan1("Ozlem","Zor",21);
	insanlar insan2("Sezen","Aksu",21);
	insanlar insan3("Cagla","Eris",20);
	
	insan1.goster();
	insan2.goster();
	insan3.goster();
	
	system("PAUSE");
	return 0;
}