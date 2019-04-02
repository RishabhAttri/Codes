#include <iostream>
using namespace std;

void PrintLexo(int n, int Max){
    if (n>Max) return;

    int ul;
    if (n==1) ul=9; else ul=n+9;
    for (int i=n;i<=ul&&i<=Max;i++){
        cout<<i<<endl;
        PrintLexo(i*10,Max);
    }


}

int main(){
    int n;cin>>n;
    PrintLexo(1,n);
}
