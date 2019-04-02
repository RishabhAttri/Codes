#include <iostream>
using namespace std;

int main(){

    int a=10;
    int *p=&a;
    int &c=a;

    int arr[5]={10,12,14,16,18};
    int *p2=arr;

    cout<<*p2<<endl;
    cout<<*p2+1<<endl;
    cout<<p2<<endl;
    cout<<p2+1<<endl;
    cout<<*(p2+1)<<endl;

    cout<<*(arr+1)<<endl;
    cout<<p2[3]<<endl;


    return 0;
    //int arr[5]={10,12,14,16,18};
    char ch[4]={'a','b','c','d'};
    int *p1=(int*)ch;

    //cout<<ch<<endl;
    cout<<*p1<<endl;



    return 0;
    cout<<p<<endl;
    cout<<&a<<endl;
    cout<<&c<<endl;

    cout<<&p<<endl;

    cout<<a<<endl;
    *p=20;
    cout<<a<<endl;

    return 0;
    *p=20;
    cout<<*p;

    int d=100;

    ///*p=&d; this is wrong
    p=&d;

}
