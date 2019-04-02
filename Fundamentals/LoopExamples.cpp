#include <iostream>
using namespace std;

int main(){
    int n,sum=0;
    cin>>n;

    int cnt=1;

    while (cnt<=n){
        ///repeat work;
        int a; cin>>a;
        sum=sum+a;
        ///sum=sum+cnt;
        ///sum=sum+2;
        ///cout <<cnt<<" ";
        cnt=cnt+1;
    }
    cout<<sum;
}
