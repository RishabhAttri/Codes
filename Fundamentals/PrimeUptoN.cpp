#include <iostream>
using namespace std;

int main(){
    int n;cin>>n;

    int i=2;


    while (i<=n){
        ///check & print if prime
        int j=2;
        bool isPrime=true;
        while (j<i){
            if (i%j==0) {
                isPrime=false;
                break;
            }
            j=j+1;
        }
        if (isPrime==true) cout<<i<<" ";
        i=i+1;
    }
}

/*
    int n;cin>>n;

    int i=2;
    while (i<=n){
        ///check & print if prime
        int j=2;
        while (j<i){
            if (i%j==0) break;
            j=j+1;
        }
        if (j==i) cout<<i<<" ";
        i=i+1;
    }
*/
