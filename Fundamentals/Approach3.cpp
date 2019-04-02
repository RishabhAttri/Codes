#include <iostream>
using namespace std;

int main(){
    int n,MaxSoFar;
    cin>>n;

    int cnt=1;
    int a;cin>>a;
    MaxSoFar=a;

    while (cnt<n){
        int a; cin>>a;
        if (a>MaxSoFar) MaxSoFar=a;
        cnt=cnt+1;
    }

    cout<<MaxSoFar;
}
