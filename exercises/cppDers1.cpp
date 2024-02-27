#include<iostream>
using namespace std;
#include <vector>
#include<string.h>
void yazdir(vector<vector<int>>&);
class Araba;

int main(int argc, char const *argv[])
{
    vector<int> sayilar;
    sayilar.push_back(5);
    sayilar.push_back(10);
    sayilar.insert(sayilar.begin(),11);
    sayilar.insert(sayilar.begin(),1);
    sayilar.insert(sayilar.begin(),42);
    sayilar.erase(sayilar.begin(),sayilar.begin()+2);

    for(auto iter = sayilar.begin(); iter != sayilar.end();++iter)
        cout << *iter << " ";
    cout << endl;
    for(int i=sayilar.size()-1; i >= 0 ;i--) cout << sayilar[i] << " ";
    vector<vector<int>> n(1,vector<int>(5));
    cout << endl;
    Araba *1 = new Araba();
    yazdir(n);
    return 0;
}


void yazdir(vector<vector<int>>& n){
    cout << n.size();
}

class Deneme{
    //erişim şekli
    public:
    private:
    protected:
    //üye degerler
    //üye fonksiyonlar
};
class Araba{
    public:
        string marka;
        string model;
        Araba();
};
Araba::Araba():marka("Tofas"),model("1994"){}
