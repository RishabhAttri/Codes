#include <iostream>
using namespace std;

void Merge(int arr[], int s, int e){
    int temp[100];
    for (int i=s;i<=e;i++) temp[i]=arr[i];
    int mid=(s+e)/2;
    int i=s,j=mid+1,k=s;

    while (i<=mid && j<=e){
        if(temp[i]<temp[j]){
            arr[k]=temp[i];
            k++;i++;
        }
        else{
            arr[k]=temp[j];
            j++;k++;
        }
    }
    while (i<=mid){
        arr[k]=temp[i];
        k++;i++;
    }
    while (j<=e){
        arr[k]=temp[j];
        j++;k++;
    }
}

void MergeSort(int arr[],int s, int e){
    if (s>=e) return;
    ///divide it in 2 parts and then sort using recursion
    int mid=(s+e)/2;
    MergeSort(arr,s,mid);
    MergeSort(arr,mid+1,e);
    Merge(arr,s,e);
}

int main(){
    int arr[]={12,4,6,10,14,2,23,16,19,8};
    MergeSort(arr,0,9);

    for (int i=0;i<10;i++) cout<<arr[i]<<" ";
}



