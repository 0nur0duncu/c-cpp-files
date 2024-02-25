#include <iostream>
using namespace std;

class Dizi {
    public:
        Dizi(unsigned int boyut); //Constructor
        ~Dizi(); //Destructor
        void yazdir();
        void operator +=(int);
        Dizi operator*(int ) const; //* aşırı yüklenmesi
        int operator [](int i) const {return pointer[i];}
        int & operator [](int i) {return pointer[i];}
        friend ostream& operator << (ostream &out, const Dizi &d);
        unsigned int boyut() const; //_boyut değerini döndür
    private:
        int * pointer; //bellek
        unsigned int _boyut; //boyut
};
Dizi::Dizi(unsigned int boyut) {
    this->_boyut=boyut;
    pointer = new int[boyut];
    for (int i = 0; i < boyut; ++i) {
        pointer[i]=0;
    }
}

Dizi::~Dizi() {
    delete pointer;
}

unsigned int Dizi::boyut() const{
    return _boyut;
}

void Dizi::yazdir(){
    for (unsigned int i = 0; i < _boyut; ++i) {
        cout << pointer[i] << " ";
    }
    cout << endl;
}

void Dizi::operator +=(int artis) {
    for (unsigned int i = 0; i < _boyut; ++i) {
        pointer[i] += artis;//artis ne arar kodda
    }
}

Dizi Dizi::operator*(int carpim) const {
    Dizi dondur(_boyut);
    for (unsigned int i = 0; i < _boyut; ++i) {
        dondur[i] = pointer[i]*carpim;
    }
    return dondur;
}

ostream & operator << (ostream &out, const Dizi &d) {
    out << "Dizi[";
    for (unsigned int i = 0; i < d.boyut(); ++i) {
        if(i!=d.boyut()-1)
            out << d[i] <<", ";
        else
            out << d[i]<<"]"<<endl;
    }
    return out;
}
