#include <iostream>
#include <cstring>
using namespace std;

void SubSequence(char sIn[],int rPos, char sOut[], int oPos){
    if (sIn[rPos]=='\0') {
        sOut[oPos]='\0';
        cout<<sOut<<endl;
        return;
    }
    sOut[oPos]=sIn[rPos];
    ///Include
    SubSequence(sIn,rPos+1,sOut,oPos+1);
    ///Exclude
    SubSequence(sIn,rPos+1,sOut,oPos);
}

int main(){
    char str[]="abcd1e2",sOut[100];
    SubSequence(str,0,sOut,0);
}
