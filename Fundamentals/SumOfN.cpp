#include <iostream>
using namespace std;

int main(){
    int n; cin>>n;

    int cnt=1,sum=0;

    while (cnt<=n){
        ///here you will perform actual task
        sum=sum+cnt;
        cnt=cnt+1;
    }
    cout<<sum;
}
