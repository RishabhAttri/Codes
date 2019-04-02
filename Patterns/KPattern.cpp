#include <iostream>
using namespace std;

int main(){
    int n=4;
    for (int i=1;i<=n;i++){
        cout<<"*";
        for (int j=1;j<=n-i;j++){
            cout<<" ";
        }
        cout<<"*";
        cout<<endl;
    }
    for (int i=n-1;i>=1;i--){
        cout<<"*";
        for (int j=1;j<=n-i;j++){
            cout<<" ";
        }
        cout<<"*";
        cout<<endl;
    }
}
