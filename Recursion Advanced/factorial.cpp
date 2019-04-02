#include <iostream>
using namespace std;

int factorial(int n){
    ///base case
    if (n==0) return 1;

    int fact;
    ///recursion call
    fact=n*factorial(n-1);
    return fact;
}

int main(){
    cout<<factorial(5);
}
