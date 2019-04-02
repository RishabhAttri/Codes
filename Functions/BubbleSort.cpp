#include<iostream>
using namespace std;

int main(){
    //int arr[16]={1,12,4,13,6,7,18,9,10,5};
    int arr[16]={1,2,4,4,6,7,8,9,10,15};
    int n=10;

    for (int i=0;i<n-1;i++){
        cout<<i<<endl;
        bool isArraySorted=true;
        for (int j=0;j<n-1-i;j++){
            if (arr[j]>arr[j+1]) {
                swap (arr[j],arr[j+1]);
                isArraySorted=false;
            }
        }
        if (isArraySorted) break;
    }
    for (int i=0;i<n;i++) cout<<arr[i]<<" ";
}

/*int main(){
    int arr[16]={1,12,4,13,6,7,18,9,10,5};
    int n=10;

    for (int i=0;i<n-1;i++){
        for (int j=0;j<n-1-i;j++){
            if (arr[j]>arr[j+1]) swap (arr[j],arr[j+1]);
        }
    }
    for (int i=0;i<n;i++) cout<<arr[i]<<" ";
}
*/
