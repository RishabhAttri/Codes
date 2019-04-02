#include <iostream>
using namespace std;

void Print(int n){
    if (n==0) return;
    char arr[][10]={"Zero","One","Two", "three","Four","Five","Six","Seven","eight","Nine"};

    int d=n%10;
    Print(n/10);
    cout<<arr[d]<< " ";

}

int main(){
    Print(2048);
}
/*
int n=2;
    char arr[][10]={"Zero","One","Two", "three","Four","Five","Six","Seven","eight","Nine"};

    cout<<arr[n];
    return 0;
    switch (n) {
        case 0: ///cout<<"zero";
                ///break;
        case 1: cout<<"one";
                break;
        case 2: cout<<"two";
                break;
        case 3: cout<<"three";
                break;
        case 4: cout<<"four";
                break;
        default: cout<<"Others";
                break;

    }
    */
