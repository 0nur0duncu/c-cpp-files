#include<iostream>

using namespace std;

class dikdortgen{
    int kisa_kenar;
    int uzun_kenar;

    public:
        
        int alan(){
            return kisa_kenar * uzun_kenar;
        }

        int cevre(){
            return 2 * kisa_kenar + 2 * uzun_kenar;
        }

        void setKisakenar(int kisa){
            this->kisa_kenar = kisa;
        }
        void setUzunkenar(int uzun){
            this->uzun_kenar = uzun;
        }
        int getKisakenar(){
            return this->kisa_kenar;
        }
        int getUzunkenar(){
            return this->uzun_kenar;
        }
}y;

int main(){

    system("CLS");
    dikdortgen x;
    x.setKisakenar(10);
    x.setUzunkenar(20);
    cout << x.alan() << endl;
    cout << x.cevre() << endl;

    y.setKisakenar(15);
    y.setUzunkenar(20);
    cout << y.alan() << endl;
    cout << y.cevre() << endl;



    return 0;
}