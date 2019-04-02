#include <iostream>
using namespace std;

void PrintText (int n){
    if (n==0) return;
    char arr[10][10]={"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};

    int d=n%10;
    n=n/10;
    PrintText(n);
    cout<<arr[d]<<" ";

}

int main(){
    PrintText(2048);
}
