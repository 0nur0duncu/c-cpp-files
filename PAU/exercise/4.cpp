#include <iostream>
#include <vector>
using namespace std;


void pascal(vector< vector< int > >& vec) {

    for(int i=0 ; i < vec.size(); i++){
        for(auto j = vec.at(i).begin();j != vec.at(i).end();++j){
            cout << *j << " ";
        }
        cout << endl;
    }

}

int main(int argc, char const *argv[])
{
    vector <vector<int>> vec;
    vector<int> vec1,vec2,vec3,vec4;
    vec1.push_back(1);
    vec2.push_back(1);
    vec2.push_back(1);
    vec3.push_back(1);
    vec3.push_back(2);
    vec3.push_back(1);
    vec4.push_back(1);
    vec4.push_back(3);
    vec4.push_back(3);
    vec4.push_back(1);
    vec.push_back(vec1);
    vec.push_back(vec2);
    vec.push_back(vec3);
    vec.push_back(vec4);


    pascal(vec);
    return 0;
}
