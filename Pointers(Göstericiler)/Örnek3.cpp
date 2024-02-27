#include<iostream>
using namespace std;
int main(){
	/*
	int a=10;
	int *ptr;
	ptr=&a;
	*ptr++;
	//bir dizi bildirmediğimiz için sonraki adreste tutulan ramdeki adresi verdi.
	cout<<*ptr<<endl;
	system("Pause");
	return 0;*/
	
	int a[5]={1,2,3,4,5};
	int *ptr;
	ptr=a;
	
	//birinci durumdaki pointerdaki sayı ve ramdeki adresi
	cout<<*ptr<<" sayisinin ramdeki adresi= "<<ptr<<endl;
	ptr++;//adresi 1 arttırdık
	//ikinci durumdaki pointerdaki sayı ve ramdeki adresi
	cout<<*ptr<<" sayisinin ramdeki adresi= "<<ptr<<endl;
	//ucuncu durumdaki pointerdaki sayı ve ramdeki adresi
	*ptr++;//icerisindeki deger 1 arttirildi.
	cout<<*ptr<<" sayisinin ramdeki adresi= "<<ptr<<endl;
	//farkedildigi uzere her adres arasında ramda 4 bytelık fark var bunun sebebi dizimizin veri tipinin int olmasidir.
	//ayrica adres ya da degerin degismesi fark etmiyor.Her turlu deger ve adres degisiyor.
	system("PAUSE");	
	return 0;
}