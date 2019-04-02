#include <iostream>
using namespace std;

int SquareRoot (int n){
    int i=0;
    for (i=0;i*i<=n;i++);
    return i-1;

}

float SquareRoot (int n, int p){
    float sqrt=0;
    int cntPrec=0; float inc=1;
    for (cntPrec=0,inc=1;cntPrec<=p;cntPrec++,inc=inc/10){
        for (;sqrt*sqrt<=n;sqrt+=inc);
        sqrt-=inc;
    }
    return sqrt;
}

int main(){
    cout<<SquareRoot(50)<<endl;
    cout<<SquareRoot(2,3)<<endl;
}

