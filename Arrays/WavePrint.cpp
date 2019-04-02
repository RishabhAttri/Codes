#include<iostream>
using namespace std;

int main(){
    int arr[4][5]={ {11,12,13,14,15},
                    {21,22,23,24,25},
                    {31,32,33,34,35},
                    {41,42,43,44,45}};
    int m=4, n=5;

    for (int c=0;c<n;c++){
        if (c%2==0) {
            for (int r=0;r<m;r++){
                cout<<arr[r][c]<<" ";
            }
        }
        else {
            for (int r=m-1;r>=0;r--){
                cout<<arr[r][c]<<" ";
            }
        }
    }

}
