#include <iostream>
using namespace std;

int main(){
    int n; cin>>n;
    int bin=0;

    for (int mf=1;n>0;n=n/2,mf=mf*10){
        int d=n%2;
        bin=d*mf+bin;
    }
    cout<<bin;
}
