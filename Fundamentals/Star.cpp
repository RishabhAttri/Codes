#include <iostream>
using namespace std;

int main(){
    int n;cin>>n;

    int i=1;
    while (i<=n){
        ///Print spaces
        int j=1;
        while (j<=n-i){
            cout<<" ";
            j=j+1;
        }

        ///Print Stars

        int k=1;
        while (k<=2*i-1){
            cout<<"*";
            k=k+1;
        }

        cout<<endl;
        i=i+1;
    }
}
