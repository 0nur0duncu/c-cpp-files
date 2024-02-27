#include<iostream>
#include<cstring>

using namespace std;

class Zaman{
    int saat,dakika,saniye;
    public:
        Zaman(int saat,int dakika,int saniye){
            this->saat = saat;
            this->dakika = dakika;
            this->saniye = saniye;
        }
        void goster(){
            cout << saat <<":"<< dakika <<":"<< saniye <<endl;
        }
};

class Ogrenciler{
    string ad,bolum;
    long TC;
    public:
        Ogrenciler(string ad,long TC,string bolum){
            this->ad = ad;
            this->TC = TC;
            this->bolum = bolum;
        }
        void goruntule_ad(){
            cout << "AD: " << ad <<endl;
        }
        void goruntule_TC(){
            cout <<"T.C. :" << TC <<endl;
        }
        void goruntule_bolum(){
            cout <<"Bolum:" << bolum << endl;
        }
        void al_ad(string ad){
            this->ad = ad;
        }
        void al_TC(long TC){
            this->TC = TC;
        }
        void al_bolum(string bolum){
            this->bolum = bolum;
        }
};

class dikdortgen{
    int kisa,uzun;
    public:
        dikdortgen(int kisa,int uzun){
            this->kisa = kisa;
            this->uzun = uzun;
        }
    friend void goruntule();
}a(15,20);

void goruntule(){
    int cevre = 2 * (a.kisa + a.uzun);
    int alan = a.kisa * a.uzun;
    cout << "cevre: " << cevre << endl <<  "alan: " << alan;
}

class bilgi{
    string ad,soyad;
    int yas;
    public:
        bilgi(){
        this->ad = "onur";
        this->soyad = "oduncu";
        this->yas = 25; 
        }
        void goster(){
            cout << "ad =" << ad << endl << "soyad=" << soyad << endl << "yas=" << yas <<endl; 
        }
};

/* class notlar{
    int grade;
    public:
        notlar(int grade){this ->grade = grade;}
        friend void al();
        friend void goster(notlar ogr);
};

void al(){
    for(int i = 0; i < 3; i++){
        int nots;
        cout << "Notunuzu giriniz...: ";
        cin >> nots;
        notlar not[i];
    }
}
void goster(){
    cout << ogr.grade;
} */

class Deneme{
    int k,l,m;
    public:
        Deneme(int k,int l,int m){
            this->k = k;
            this->l = l;
            this->m = m;
        }
        friend void goster(Deneme o);
};
void goster(Deneme o){
    cout << o.k <<" "<< o.l << " " << o.m << endl;
}

class yap_yik{
    int sayi;
    public:
        yap_yik(int sayi){
            this->sayi = sayi;
            cout << sayi <<". yapici calisti" << endl;
        }
        ~yap_yik(){
            cout << sayi << ". yikici calisti" << endl;
        }
};

class Personel{
    string ad, soyad;
    public:
        Personel(string ad, string soyad){
            this -> ad = ad;
            this -> soyad = soyad;
        }
        void gosterPers();
};

void Personel::gosterPers(){
    cout << ad << " " << soyad; 
}

class Ev{

    int daireNo,katNo,kira;
    string il;
    public:
        Ev(int daireNo,int katNo,int kira,string il){
            this->daireNo = daireNo;
            this->katNo = katNo;
            this->kira = kira;
            this->il = il;
        }
        friend void gosterEv(Ev evler);   

};
void gosterEv(Ev evler){
    cout << evler.daireNo << "-" << evler.il <<"-" << evler.katNo << "-" << evler.kira <<endl;
}

int main(int argc, char const *argv[])
{
    system("CLS");
    //------------------ 1 -------------------------

    /* Zaman time(11,04,22);
    time.goster(); */

    //------------------ 2 -------------------------

    /* Ogrenciler ogrenci1("a",123456,"b"),ogrenci2("c",123456,"d"),ogrenci3("e",123456,"f");
    ogrenci1.goruntule_ad();
    ogrenci2.goruntule_ad();
    ogrenci3.goruntule_ad(); */

    //------------------ 3 -------------------------

    //goruntule();
    
    //------------------ 4 -------------------------

    //bilgi kisi;
    //kisi.goster();

    //------------------ 5 -------------------------

    /* al(nots,ogr1);

    cout << "Notunuzu giriniz...: ";
    cin >> nots;
    al(nots,ogr2);

    goster(ogr1);
    goster(ogr2); */

    //------------------ 6 -------------------------

    /* Deneme durum1(5,7,9),durum2(2,4,7),durum3(8,7,0);
    goster(durum1);
    goster(durum2);
    goster(durum3); */

    //------------------ 7 -------------------------

    //yap_yik nesne1(1),nesne2(2),nesne3(3);

    //------------------ 8 -------------------------

    /* Personel pers1("onur", "oduncu"),pers2("ahmet","oduncu");
    pers2 = pers1;
    pers2.gosterPers(); */

    //------------------ 9 -------------------------

    Ev ev1(5,4,3,"a"),ev2(3,5,7,"b");
    gosterEv(ev1);

    //----------------------------------------------
    cout << endl;
    return 0;
}
