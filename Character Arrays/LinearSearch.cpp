#include<iostream>
using namespace std;

int main(){
    int n;cin>>n;

    int arr[100];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"Please enter number to be searched:";
    int a; cin>>a;
    bool isNumberFound=false;

    for (int i=0;i<n;i++){
        if (arr[i]==a) {
            cout<<"Number exists at index:" <<i<<endl;
            isNumberFound=true;
        }
    }
    if( !isNumberFound) cout<<"Number not Found";

}

