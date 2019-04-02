#include <iostream>
using namespace std;

int FiboNth(int n){
    if (n==0||n==1) return n;

    int fibo= FiboNth(n-1)+ FiboNth(n-2);
    return fibo;
}


int main(){
    cout<<FiboNth(7);
}
