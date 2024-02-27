#include<iostream>

using namespace std;

void fakt(int *sayilarPtr,int uzunluk);
void fakt2 (int *sayi);

int main(int argc, char const *argv[])
{
    system("CLS");

    //--------------1----------------------------

    /* int a, *aptr;
    cout << "Lutfen bir sayi giriniz....:";
    cin >> a;
    aptr = &a ;
    cout << a << " sayisinin bellekteki adresi = " << aptr ; */

    //-------------- 2 ----------------------------

    /* char a[20] , *aptr , i =0;
    cout << "Lutfen bir kelime giriniz....:";
    gets(a);
    aptr = a;

    while (*(aptr+i) != NULL)
    {
        cout << *(aptr + i++);
    } */
    
    //-------------- 3 ----------------------------

    /* char name[] = "onuroduncu", *namePtr;
    namePtr = name ;

    cout << "++*ptr = " << ++*namePtr << endl;
    cout << "*++ptr = " << *++namePtr << endl;
    cout << "*ptr++ = " << *namePtr++ << endl;
    cout << "++*ptr++ = " << ++*namePtr++ << endl;
    cout << "*++ptr++ = " << (*++namePtr)++ << endl;
    cout << "&*ptr = " << &*namePtr << endl;
    cout << "*&ptr = " << *&namePtr << endl; */

    //-------------- 4 ----------------------------

    /* int sayilar[10];

    for(short i = 0; i<10 ; i++){
        cout << i+1 <<". sayi = ";
        cin >> sayilar[i];    
    }
    fakt(sayilar,10); */

    //-------------- 5 ----------------------------

    int sayi;
    void (*fonk)(int);
    fonk = fakt2;

    cout << "Lutfen sayiyi giriniz...: ";
    cin >> sayi;
    cout << fonk(sayi);

    //-------------- 6 ----------------------------



    cout << endl;
    system("PAUSE");
    return 0;
}

void fakt(int *sayilarPtr,int uzunluk){
    for(short i = 0 ; i < uzunluk ; i++){
        int carpim = 1;
        for(short j = *(sayilarPtr + i); j >1 ; j--){
            carpim *=j;
        }
        cout << *(sayilarPtr + i) << "'nin faktoriyeli = "<<carpim << endl;
    }
    
}

void fakt2 (int *sayi){
    int carpim = 1;
    for(short j = *(sayi); j >1 ; j--)
        carpim *=j
}