#include<iostream>
#include<vector>
using namespace std;
/**
 * @brief Program girilen sayıları tekrarsız biçimde aynı sırada ekrana yazdırır.
 *
 * Kullanıcı -1 girene kadar kullanıcıdan sayılar alınacaktır. Kullanıcı -1 girdiğinde
 * sayı alma sonlandırılarak girilen sayıları tekrarsız biçimde girdideki sıralarıyla
 * ekrana yazdıran C++ programını yazınız. Programın örnek çalışması aşağıda verilmiştir:
 *
 * Girdi:
 * 5
 * 2
 * 1
 * 5
 * 5
 * 1
 * 3
 * 2
 * -1
 * Çıktı:
 * 5
 * 2
 * 1
 * 3
 *
 * İpucu: Girilecek sayı adeti bilinmediği için vector yapısı kullanılabilir.
 */

int main(int argc, char const *argv[])
{
    vector<int> inputs;
    int number;
    while(true){
        cin>>number;
        if(number == -1) break;
        bool statue = true;
        for(int i=0; i < inputs.size();i++)
            if (inputs[i] == number) statue = false;
        if (statue)
            inputs.push_back(number);
    }
    for(int i=0; i< inputs.size();i++)
        cout<<inputs[i]<<endl;
    return 0;
}
