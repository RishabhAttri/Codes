#include <iostream>
using namespace std;

int main(){
    int n=4;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i;j++){
            cout<<" ";
        }
        for (int k=1;k<=n;k++){
            if(i==1 || i==n || k==1 || k==n) cout<<"*"; else cout<<" ";
        }
        cout<<endl;
    }
}
