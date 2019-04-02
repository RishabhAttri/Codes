#include<iostream>
using namespace std;

int main(){
    char str[]="CodingBlocks";
    int k=3, n=12;

    char temp[100];

    for (int i=0;i<k;i++){
        temp[i]=str[n-k+i];
    }

    for (int i=n-k-1;i>=0;i--){
        str[i+k]=str[i];
    }

    for (int i=0;i<k;i++){
        str[i]=temp[i];
    }

    cout<<str;

}
