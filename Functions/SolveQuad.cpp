#include<iostream>
#include<cmath>
using namespace std;


void SolveQuad(int a, int b, int c, bool &SolExist, float &out1, float &out2){

    int d=b*b-4*a*c;
    if (d>=0){
        SolExist=true;
        out1=(-b+sqrt(d))/(2*a);
        out2=(-b-sqrt(d))/(2*a);
    }

}

int main(){
    int a=1,b=4,c=4;
    float o1,o2;
    bool SolExist=false;
    SolveQuad(a,b,c,SolExist,o1,o2);
    if (SolExist) cout<<o1<<" "<<o2;
}
