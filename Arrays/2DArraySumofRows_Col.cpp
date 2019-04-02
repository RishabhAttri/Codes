#include<iostream>
using namespace std;

int main(){
    int arr[100][100]={0};
    int m=3, n=4;

    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }

    //print sum of each column
    int sum;
    for (int c=0;c<n;c++){
        sum=0;
        for (int r=0;r<m;r++){
            sum+=arr[r][c];
        }
        cout<<sum<<" ";
    }

    //print sum of each row;
    for (int r=0;r<m;r++){
        sum=0;
        for (int c=0;c<n;c++){
            sum+=arr[r][c];
        }
        cout<<sum<<endl;
    }
}
