#include<iostream>
using namespace std;

inline int dikdortgenAlan(int kisa,int uzun){
    return kisa*uzun;
}

int main(){
    cout << "dikdortgenin Alani = " << dikdortgenAlan(5,7) << endl;
    return 0;
}