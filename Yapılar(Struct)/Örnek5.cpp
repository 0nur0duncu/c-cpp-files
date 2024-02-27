#include<iostream>
using namespace std;
struct tarih{
	int gun,ay,yil;
}bugun,dogum,sonuc;
struct tarih yas();//fonksiyonun prototipi
int main(){
	cout<<"Bugunun tarihini(gun,ay.yil) giriniz....: "<<endl;
	cin>>bugun.gun>>bugun.ay>>bugun.yil;
	cout<<"Dogum tarihinizi(gun,ay.yil) giriniz....: "<<endl;
	cin>>dogum.gun>>dogum.ay>>dogum.yil;
	yas();
	cout<<sonuc.yil<<" yil, "<<sonuc.ay<<" ay, "<<sonuc.gun<<" gundur"<<" hayattasin."<<endl;
	system("Pause");
	return 0;
}
struct tarih yas(){
	if(bugun.gun<dogum.gun){
	bugun.ay-=1;
	sonuc.gun=30+bugun.gun-dogum.gun;
	}else sonuc.gun=bugun.gun-dogum.gun;
	if(bugun.ay<dogum.ay){
	bugun.yil-=1;
	sonuc.ay=12+bugun.ay-dogum.ay;
	}else sonuc.ay=12+bugun.ay-dogum.ay;
	sonuc.yil=bugun.yil-dogum.yil;
	return sonuc;
}