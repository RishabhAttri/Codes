#include <iostream>
using namespace std;

int FindSum(int arr[],int size){
    int sum=0;
    for (int i=0;i<size;i++) sum+=arr[i];
    return sum;

}

int main(){
    int n;cin>>n;
    int arr[100];

    for (int i=0;i<n;i++) cin>>arr[i];

    int sum=FindSum(arr,n);

    cout<<sum<<endl;
}
