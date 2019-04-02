#include <iostream>
using namespace std;

bool Find7_search(int arr[], int n){
    if (n==0) return false;
    if (arr[0]==7) return true;
    return Find7_search(arr+1,n-1);
}

int Find7_LeftIndex(int arr[], int n, int s){
    if (n==s) return -1;
    if (arr[s]==7) return s;
    return Find7_LeftIndex(arr,n,s+1);
}

int Find7_LeftIndex1(int arr[], int n, int depth){
    if (n==0) return -1;
    if (arr[0]==7) return depth;
    return Find7_LeftIndex1(arr+1,n-1,depth+1);
}

int Find7_RightIndex (int arr[], int n){
    if (n==0) return -1;

    if (arr[n-1]==7) return n-1;
    return Find7_RightIndex(arr,n-1);
}

int Find7_RightIndex1 (int arr[], int n, int s){
    if (n==s) return -1;

    int RightFound=Find7_RightIndex1(arr,n,s+1);
    if (RightFound!=-1) return RightFound;
    if (arr[s]==7) return s; else return -1;
}

int Find7_RightIndex2 (int arr[], int n, int s, int lf){
    if (n==s) return lf;

    if (arr[s]==7) lf=s;
    return Find7_RightIndex2(arr,n,s+1,lf);
}

void Find7_allIndex(int arr[], int n, int s){
    if (n==s) return;
    if (arr[s]==7) cout<<s<<" ";
    Find7_allIndex(arr,n,s+1);
}

int main()
{
    int arr[]={1,2,17,4,5,6,17,8,9,10};
    //cout<<Find7_search(arr,10);
    //cout<<Find7_LeftIndex1(arr,10,0);
    //cout<<Find7_RightIndex(arr,10);
    //Find7_allIndex(arr,10,0);
    //cout<<Find7_RightIndex1(arr,10,0);
    cout<<Find7_RightIndex2(arr,10,0,-1);

}
