#include <iostream>
using namespace std;

int main(){
    int n; cin>>n;
    int hn=(n+1)/2,re,ce;

    for(int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if (i<=hn) re=i; else re=n-i+1;
            if (j<=hn) ce=j; else ce=n-j+1;
            ///if(re+ce>=hn+1)
            if(re==ce)
                cout<<"* "; else cout<<". ";
        }
        cout<<endl;
    }
}
