#include<iostream>
#include<list>
using namespace std;

int main(){
    list<int> ll;

    ll.push_back(1);
    ll.push_front(2);
    ll.push_back(3);
    ///list<int>::iterator
    for ( auto it=ll.begin();it!=ll.end();it++){
        int n=*it;
        cout<<n<<"->";
    }

}
