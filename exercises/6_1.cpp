#include<iostream>
#include<cstring>
using namespace std;

int main(int argc, char const *argv[])
{
    system("CLS");

    //-------------- 1 ----------------------------
    /* int sayilar[] = {1,9,7,3,4,6,2,8};
    for( int i =0 ; i <8 ; i++ ){
        int sakla = i;
        for(int j = i+1 ; j < 8 ; j++ ){
            if (sayilar[j] < sayilar[sakla]) sakla = j;                   
        }

        int gecici = sayilar[i];
        sayilar[i] = sayilar[sakla];
        sayilar[sakla] = gecici;

    }
    for(int i=0; i<8 ; i++) cout<<sayilar[i]<<"\t"; */

    //-------------- 2 ----------------------------

    /* int sayilar[10];

    for(int i=0 ; i < 10 ; i++){
        cout<< i+1 <<". sayi = ";
        cin>> sayilar[i];
    }
    for(int i=0; i<10 ; i++) cout<<sayilar[i]<<"\t"; */

    //-------------- 3 ----------------------------

    /* int sayilar[] = {1,2,3,4,5,6,7,8,9,10},carpim = 1;
    for(int i=0; i<10 ; i++) carpim *= sayilar[i];
    cout << "carpimin sonucu = " << carpim ; */

    //-------------- 4 ----------------------------

    /* char isim[20];
    cout << "isim - soyisim = ";
    gets(isim);
    puts(isim);

    char isim2[20];
    cout << "il - ilce= ";
    cin >> isim2;
    puts(isim2); */

    //-------------- 5 ----------------------------

    /* char metin[20],metin_cpy[20];
    cout << "Kelime giriniz....: ";
    gets(metin);

    for(int i = 0 ; i < strlen(metin); i++ ){
        metin_cpy[i] = metin[strlen(metin) - i -1];
    }  
    puts(metin_cpy);
    cout << strrev(metin) << endl; */

    //-------------- 6 ----------------------------

    /* int A[2][2], B[2][2], C[2][2];

    for(int i = 0; i < 2; i++)
    for(int j = 0; j <2 ; j++){
        cout <<"A["<< i << "][" << j <<"] = ";
        cin >> A[i][j]; 
    }
    for(int i = 0; i < 2; i++)
    for(int j = 0; j <2 ; j++){
        cout <<"B["<< i << "][" << j <<"] = ";
        cin >> B[i][j]; 
    }

    C[0][0] = A[0][0] * B[0][0] + A[0][1]* B[1][0];
    C[0][1] = A[0][0] * B[0][1] + A[0][1]* B[1][1];
    C[1][0] = A[1][0] * B[0][0] + A[1][1]* B[1][0];
    C[1][1] = A[1][0] * B[0][1] + A[1][1]* B[1][1];

    for(int i = 0; i < 2; i++)
    for(int j = 0; j <2 ; j++){
        cout <<"C["<< i << "][" << j <<"] = " << C[i][j]<<endl;

    } */

    //-------------- 7 ----------------------------

    /* int fibo[15];
    fibo[0] = 0;
    fibo[1] = 1;
    for(int i = 1 ; i < 14 ; i++ ) fibo[i + 1 ] = fibo[ i ] + fibo [ i -1 ];
    for(int i = 0 ; i < 15 ; i++ ) cout << fibo[i] <<"\t"; */

    //-------------- 8 ----------------------------

    int CT[10][10];

    for(int i = 0 ; i < 10 ; i++)
    for(int j = 0 ; j < 10 ; j++) CT[i][j] = (i+1) * (j+1);
    
    for(int i = 0; i < 10; i++){
        cout << "| ";
        for(int j = 0; j < 10 ; j++)
            cout << CT[i][j]<<"\t";
        cout<<"|" << endl;
    }
    cout<<endl;
    system("PAUSE");
    return 0;
}
