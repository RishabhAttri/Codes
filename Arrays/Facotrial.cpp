#include<iostream>
using namespace std;

int factorial(int a){
    if (a==0) return 1;
    int f= a*factorial(a-1);
    return f;
}

int main(){
    cout<<factorial(5);
}
