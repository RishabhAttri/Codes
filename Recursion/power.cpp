#include <iostream>
using namespace std;

int power(int x, int n){
    if (n==0) return 1;
    int res=power(x,n/2);
    if (n%2==0) return res*res; else return res*res*x;
}

int main(){
    cout<<power(2,20);
}
