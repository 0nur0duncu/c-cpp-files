#include<iostream>
using namespace std;
double kare(double x){
	x*=x;
	return x;
}
int main(){
	double kenar;
	double (*fonk)(double);
	fonk=kare;
	cout<<"Karenin bir kenarini metre olarak giriniz...:";
	cin>>kenar;
	cout<<"Karenin alani: "<<fonk(kenar)<<" metre kare"<<endl;
	cout<<endl;
	system("Pause");
	return 0;
}