#include<iostream>
using namespace std;
int a1=150;

void Swap(int &a, int &b){
    ///swap(a,b);
    int temp=a;
    a=b;
    b=temp;
}


int main(){
    int a=20;
    int b=10;

    cout<<a<<" "<<b<<endl;
    Swap(a,b);
    cout<<a<<" "<<b<<endl;

    ///Reference Variable
    int &c=a;

    cout<<c<<endl;
    c=15;
    cout<<a<<endl;
    int j;
    for (j=1; j<10;j++){

    };

    cout<<j<<endl;

    int a1=115;
    {
        int a1;
        a1=100;
        cout<<a1<<endl;
    }
    cout<<a1<<endl;
    cout<<::a1<<endl;
}
