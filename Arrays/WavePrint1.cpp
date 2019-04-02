#include<iostream>
using namespace std;

int main(){
    int arr[4][5]={ {11,12,13,14,15},
                    {21,22,23,24,25},
                    {31,32,33,34,35},
                    {41,42,43,44,45}};
    int m=4, n=5;
    int inc=1, ar=0;

    for (int c=0;c<n;c++){

        for (int r=0;r<m;r++,ar+=inc){
            cout<<arr[ar][c]<<" ";
        }
        ar-=inc; inc=inc*-1;
    }

}
