#include<iostream>
using namespace std;

void MergeArrays(int a1[],int s1,int a2[], int s2){
    int i=s1-1,j=s2-1,k=s1+s2-1;
    while (i>=0 && j>=0){
        if (a1[i]>a2[j]){
            a1[k]=a1[i];
            i--;k--;
        }
        else{
            a1[k]=a2[j];
            j--;k--;
        }
    }
    while (j>=0){
        a1[k]=a2[j];
        j--;k--;
    }
}

int main(){
    int a1[100]={1,3,5,7,9}, a2[100]={2,4,6,8},m=5,n=4;
    MergeArrays(a1,m,a2,n);
    for (int i=0;i<m+n;i++) cout<<a1[i]<<" ";

}
