#include<iostream>
#include<vector>

using namespace std;
void yazdir(vector<int>);
void yazdir2(vector<int>);

int main(int argc, char const *argv[])
{
    vector<int> sayilar;
    sayilar.push_back(3);
    sayilar.push_back(5);
    sayilar.push_back(7);
    sayilar.push_back(9);
    sayilar.insert(sayilar.begin(),11);
    sayilar.insert(sayilar.begin()+2, 13);
    yazdir(sayilar);
    sayilar.erase(sayilar.begin(), sayilar.begin()+2);
    yazdir2(sayilar);
    return 0;
}
void yazdir(vector<int> v) {
    for (auto iter = v.begin(); iter != v.end(); ++iter)
    {
    cout << *iter << " ";
    }
    cout << endl;
}
void yazdir2(vector<int> v) {
    for (int i = 0; i < v.size(); ++i)
    {
    cout << v[i] << " ";
    }
    cout << endl;
}
