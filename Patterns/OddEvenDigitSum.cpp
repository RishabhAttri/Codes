#include <iostream>
using namespace std;

int main(){
    int n; cin>>n;
    int sume=0, sumo=0, dp=1;

    while (n>0){
        int d=n%10;
        if (dp%2==0) sume=sume+d; else sumo=sumo+d;
        dp=dp+1;
        n=n/10;
    }
    cout<<sume<<" "<<sumo;
}
