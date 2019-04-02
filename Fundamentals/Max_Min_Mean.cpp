#include <iostream>
using namespace std;

int main(){
    int n,MaxSoFar;
    cin>>n;

    int cnt=1;

    while (cnt<=n){
        int a; cin>>a;
        if (cnt==1) MaxSoFar = a; else
        if (a>MaxSoFar) MaxSoFar=a;
        cnt=cnt+1;
    }

    cout<<MaxSoFar;
}

/*
Approach 1
int n,MaxSoFar=INT_MIN;
    cin>>n;

    int cnt=1;

    while (cnt<=n){
        int a; cin>>a;
        if (a>MaxSoFar) MaxSoFar=a;
        cnt=cnt+1;
    }

    cout<<MaxSoFar;
*/
