#include <iostream>
using namespace std;

void InverseArray(int *arr, int n, int s){
    if (s==n) return;

    int val=arr[s];
    InverseArray(arr,n,s+1);
    arr[val]=s;
}

int main(){
    int arr[]={3,2,1,4,0};
    InverseArray(arr,5,0);
    for (int i=0;i<5;i++) cout<<arr[i]<<" "; cout<<endl;
}
