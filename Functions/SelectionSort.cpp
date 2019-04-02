#include<iostream>
using namespace std;

int main(){
    int arr[16]={1,12,4,13,6,7,18,9,10,5};
    int n=10;

    for (int i=0;i<n-1;i++){
        int SmallestIndex=i;
        for (int j=i+1;j<n;j++){
            if (arr[j]<arr[SmallestIndex]) SmallestIndex=j;
        }
        swap(arr[i],arr[SmallestIndex]);
    }

    for (int i=0;i<n;i++) cout<<arr[i]<<" ";
}
