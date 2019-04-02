#include <iostream>
using namespace std;

bool is7Found(int * arr, int size){
    if (size==0) return false;
    if (arr[0]==7) return true;
    return is7Found(arr+1,size-1);
}

int FindFirst7(int*arr, int size, int sp){
    if (size==sp) return -1;
    if (arr[sp]==7) return sp;
    return FindFirst7(arr,size,sp+1);
}

int FindLast7_1(int*arr, int size){
    if (size==0) return -1;
    if (arr[size-1]==7) return size-1;
    return FindLast7_1(arr,size-1);
}

int FindLast7_2(int*arr, int size, int sp){
    if (size==sp) return -1;
    int ChotaFoundIndex=FindLast7_2(arr,size,sp+1);
    cout<<"C"<<ChotaFoundIndex<<endl;
    if (ChotaFoundIndex!=-1) return ChotaFoundIndex;
    if (arr[sp]==7) return sp; else return -1;
}

int main(){
    int arr[10]={1,2,7,4,5,6,7,8,9,0};
    cout<<is7Found(arr,10)<<endl;
    cout<<FindFirst7(arr,10,0)<<endl;
    cout<<FindLast7_1(arr,10)<<endl;
    cout<<FindLast7_2(arr,10,0)<<endl;

}
