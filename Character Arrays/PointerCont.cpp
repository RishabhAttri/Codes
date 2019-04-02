#include<iostream>
using namespace std;

int &test (int arr[],int &position){
    int data= arr[position];
    //position = position +1;
    return arr[position];
}

void test1 (int *p){
    cout<<*p<<endl;
    *p=40;
}

int main(){
    int a=10;
    int &b=a;

    int *c=&a;
    *c=20;

    int **pp=&c;
    int ***ppp=&pp;

    cout<<*pp<<endl;
    cout<<&a<<endl;
    cout<<**ppp<<endl;

    return 0;
    int arr[10]={0,1,2,3,4,5,6,7};

    int *p=arr;
    cout<<*(p+3)<<endl;
    cout<<p[3]<<endl;

    test1(c);
    cout<<*c<<endl;


    /*int d=arr[3];
    cout<<d<<endl;

    int pos=4;
    int &d1=test(arr,pos);
    d1=12;
    cout<<arr[4]<<endl;*/

}
