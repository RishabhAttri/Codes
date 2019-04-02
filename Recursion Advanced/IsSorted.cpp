#include <iostream>
using namespace std;

bool isSorted1 (int *arr, int n){
    if(n<=1) return true;

    /*if (arr[0]<=arr[1] && isSorted1(arr+1,n-1)) return true
        else return false;*/

    return (arr[0]<=arr[1] && isSorted1(arr+1,n-1));

}
bool isSorted2 (int *arr, int n){
    if(n<=1) return true;
    return (arr[n-1]>=arr[n-2] && isSorted1(arr,n-1));
}

void isSorted3 (int *arr, int n){
    if (n<=1) {
        cout<<"sorted"<<endl;
        return;
    }
    if (arr[0]>arr[1]){
        cout<<"Not Sorted"<<endl;
        return;
    }
    isSorted3(arr+1,n-1);
}
int main(){
    int a[]={12,5,6,8,10};
    int b[]={1,2,3,4,5,6,7};

    cout<<isSorted1(a,5)<<endl;
    cout<<isSorted1(b,7)<<endl;
    cout<<isSorted2(a,5)<<endl;
    cout<<isSorted2(b,7)<<endl;
    isSorted3(a,5);
    isSorted3(b,7);
}
