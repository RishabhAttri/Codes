#include <iostream>
using namespace std;

void PrintNumbers(int n){
    ///Base case - Smallest prob
    if (n==0) return;
    ///Recusrive call
    cout<<n<<endl;
    PrintNumbers(n-1);
    cout<<n<<endl;


}

int main(){
    PrintNumbers(5);
}
