#include <iostream>
using namespace std;

void SumPair(int arr[], int n, int x){
    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
           if (arr[i]+arr[j]==x) cout<<i<<":"<<arr[i]<<"+"<<j<<":"<<arr[j]<<endl;
        }
    }

}

int main(){
    int n;cin>>n;
    int arr[100];

    for (int i=0;i<n;i++) cin>>arr[i];

    int x; cin>>x;

    SumPair(arr,n,x);

}
