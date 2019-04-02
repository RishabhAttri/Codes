#include <iostream>
using namespace std;

int main(){
    int n;cin>>n;
    int i=1,seq=1;
    while (i<=n){
        int j=1;
        while (j<=i){
            cout<<seq;
            j=j+1;
            seq=seq+1;
        }
        cout<<endl;
        i=i+1;
    }
}

/*
int main(){
    int n;cin>>n;
    int i=1;
    while (i<=n){
        int j=1;
        while (j<=i)
            cout<<"*";
            j=j+1;
        }
        cout<<endl;
        i=i+1;
    }
}
*/

/*
int main(){
    int n;cin>>n;
    int i=1;
    while (i<=n){
        int j=1;
        while (j<=i){
            cout<<j;
            j=j+1;
        }
        cout<<endl;
        i=i+1;
    }
}
*/
