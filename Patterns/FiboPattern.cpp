#include <iostream>
using namespace std;

int main(){

    int a=0, b=1;
    int n; cin>>n;
    int i=1;
    while (i<=n){
        int j=1;
        while (j<=i){
            cout<<a<<" ";
            int s=a+b;
            a=b;b=s;
            j=j+1;
        }
        cout<<endl;
        i=i+1;
    }
}

/*int a=0, b=1;

    while (a<=50) {
        cout<<a<<" ";
        int s=a+b;
        a=b;
        b=s;
    }*/
