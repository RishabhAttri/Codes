#include <iostream>
using namespace std;

int sum(int *arr, int n){
    ///base case
    if(n==0) return 0;
    ///rec call
    int s=arr[0]+sum(arr+1,n-1);
    return s;
}

int sum1(int *arr, int n){
    if (n==0) return 0;
    int s=sum1(arr,n-1)+arr[n-1];
    return s;
}

int sum2 (int *arr, int n, int s){
    if (s==n) return 0;
    int sm=sum2(arr,n,s+1)+arr[s];
    return sm;
}

int main(){
    int arr[]={12,6,3,8,10};

    cout<<sum(arr,5)<<endl;
    cout<<sum1(arr,5)<<endl;
    cout<<sum2(arr,5,0)<<endl;
}
