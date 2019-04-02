#include<iostream>
using namespace std;

int main(){
    int arr[16]={1,2,4,5,6,7,18,19,20,25};
    int n=10;

    int tobeSearched=16;

    int s=0,e=n-1;
    while (s<=e){
        int mid=(s+e)/2;
        if (arr[mid]==tobeSearched){
            cout<<"Number found at index:"<<mid;
            return 0;
        }
        if(arr[mid]<tobeSearched) s=mid+1; else e=mid-1;
    }
    cout<<"Number Not Found";

}
