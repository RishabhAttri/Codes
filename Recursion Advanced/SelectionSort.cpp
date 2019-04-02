#include <iostream>
using namespace std;

void SelectionSort (int *arr, int n){
    if (n<=1) return;

    int smallestIndex=0;
    for (int i=1;i<n;i++){
        if (arr[i]<arr[smallestIndex]) smallestIndex=i;
    }
    swap(arr[0],arr[smallestIndex]);

    SelectionSort(arr+1,n-1);

}

int main(){
    int arr[]={7,13,5,16,20,22,9};
    SelectionSort (arr,7);
    for (int i=0;i<7;i++) cout<<arr[i]<<" "; cout<<endl;
}
