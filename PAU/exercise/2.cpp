#include <iostream>
#include <clocale>

using namespace std;
class Araba
{
    public:
        string marka;
        string model;
        int modelyili;
        Araba():marka("Tofaş"), model("Şahin"), modelyili(1995) {}
        Araba(string marka, string model, int modelyili) {
        this->marka = marka;
        this->model = model;
        this->modelyili = modelyili;
        }
        void yazdir();

};
void Araba::yazdir() {
    cout << marka << " " << model << " " << modelyili << endl;

}

class Dizi {
    public:
        Dizi(int boyut) {//Constructor
        this->boyut = boyut;
        bellek = new int[boyut];//Yeni dizi oluşturma
        for (int i = 0; i < boyut; i++)
        bellek[i] = i;//İlk değerler
        }
        ~Dizi(){
        cout << "Yıkıcı çalışıyor. Boyut: " << boyut << endl;
        delete bellek;
        }
        int al(int eleman) {//İstenilen konumdaki elemanı verir
        return bellek[eleman];//Hataya açık
        }
    private:
        int * bellek;
        int boyut;
};

class Islemler {
    public:
        int topla(int x, int y){
            return x+y;
        }
        int topla(int x, int y, int z){
            return x+y+z;
        }
        double topla(double x, double y){
            return x+y;
        }
};

class Ogrenci{
    public:
        string adi;
};

int main(int argc, char* argv[])
{ //Farklı kullanımları
    //setlocale(LC_ALL,"tr_TR.UTF-8");
    Araba a1;
    a1.marka = "Hyundai";
    a1.model = "Accent";
    a1.modelyili = 2010;
    a1.yazdir();
    Araba a2("Toyota", "Corolla", 1998);
    a2.yazdir();
    Araba a3;
    a3.yazdir();

    Araba *a4=new Araba();
    a4->yazdir();


    for (int i = 5; i < 10; i++) {
        Dizi a(i);
        cout << a.al(9-i) << endl;
    }


    Ogrenci o1, *o2;
    o1.adi="Ayşe";
    o2=new Ogrenci;
    o2->adi="Ali";
    cout << o1.adi << " " << o2->adi << endl;

    Islemler a;
    cout << a.topla(5,7) << endl;
    return 0;
}
