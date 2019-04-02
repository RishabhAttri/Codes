#include<iostream>
using namespace std;

int Factorial(int a){
    int f=1;
    for (int i=1;i<=a;i++){
        f=f*i;
    }
    return f;
}

int main(){
    ///lets find NCR

    int n=5, r=3;
    int nf=Factorial(n);
    int rf=Factorial(r);
    int nrf=Factorial(n-r);

    cout<<nf/(rf*nrf);
    //cout<<Factorial(n)/(Factorial(r)*Factorial(n-r));
    return 0;
}


/*
int main(){
    ///lets find NCR

    int n=5, r=3;

    int nf=1;
    for (int i=1;i<=n;i++){
        nf=nf*i;
    }
    int nrf=1;
    for (int i=1;i<=n-r;i++){
        nrf=nrf*i;
    }
    int rf=1;
    for (int i=1;i<=r;i++){
        rf=rf*i;
    }

    cout<<nf/(rf*nrf);
}*/
