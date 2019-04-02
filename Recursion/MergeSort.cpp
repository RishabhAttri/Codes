#include <iostream>
using namespace std;

void MergeArray(int *arr,int sIndex, int lIndex){
    int temp[100];
    for (int i=sIndex;i<=lIndex;i++){
        temp[i]=arr[i];
    }
    int mid=(sIndex+lIndex)/2;

    int i=sIndex, j=mid+1, k=sIndex;
    while (i<=mid && j<=lIndex){
        if(temp[i]<temp[j]){
            arr[k]=temp[i];
            i++;k++;
        }
        else {
            arr[k]=temp[j];
            j++;k++;
        }
    }
    while (i<=mid){
        arr[k]=temp[i];
        i++;k++;
    }
    while (j<=lIndex){
        arr[k]=temp[j];
        j++;k++;
    }
}

void MergeSort(int*arr, int sIndex, int lIndex){
    if (sIndex>=lIndex) return; ///base case
    ///Divide them in 2 parts
    int mid=(sIndex+lIndex)/2;
    MergeSort(arr,sIndex,mid);
    MergeSort(arr,mid+1,lIndex);
    ///Merge Sorted Array
    MergeArray(arr,sIndex,lIndex);
}

int main(){
    int arr[]={1,13,2,15,8,9};
    int n=6;

    MergeSort(arr,0,n-1);
    for (int i=0;i<n;i++) cout<<arr[i]<<" ";

}
