#include<iostream>
using namespace std;

int main(){
    int arr[16]={1,2,4,2,2,1,4,3,1,2,4,2,2,1,4,3};
    int n=16;

    int tm[5]={};

    for (int i=0;i<n;i++){
        tm[arr[i]]++;
    }

    int seq=0;
    for (int i=0;i<=4;i++){
        for (int j=1;j<=tm[i];j++,seq++)
            arr[seq]=i;
    }

    for (int i=0;i<n;i++) cout<<arr[i]<<" ";

}

