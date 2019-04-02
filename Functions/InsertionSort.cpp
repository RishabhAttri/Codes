#include<iostream>
using namespace std;

int main(){
    int arr[16]={1,12,4,13,6,7,18,9,10,5};
    int n=10;

    for (int i=1;i<n;i++){
        int temp=arr[i];
        int j;
        for (j=i-1;arr[j]>temp&&j>=0;j--){
            arr[j+1]=arr[j];
        }
        arr[j+1]=temp;
    }
    for (int i=0;i<n;i++) cout<<arr[i]<<" ";
}
