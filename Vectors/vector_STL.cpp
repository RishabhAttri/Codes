#include<iostream>
#include <vector>
using namespace std;


int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    cout<<v.at(3)<<endl;
    cout<<v[2]<<endl;
    cout<<v.size()<<endl;
    v.pop_back();
    cout<<v.size()<<endl;
    cout<<v.empty()<<endl;










}
