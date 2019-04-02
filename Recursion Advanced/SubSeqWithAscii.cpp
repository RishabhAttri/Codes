#include <iostream>
#include <cstring>
using namespace std;

void SubSequence(char sIn[],int rPos, char sOut[], int oPos){
    if (sIn[rPos]=='\0') {
        sOut[oPos]='\0';
        cout<<sOut<<endl;
        return;
    }
    ///Include as char
    sOut[oPos]=sIn[rPos];
    SubSequence(sIn,rPos+1,sOut,oPos+1);
    ///Include Ascii value
    int ascii=sIn[rPos];
    sOut[oPos]=ascii/10+'0';
    sOut[oPos+1]=ascii%10+'0';
    SubSequence(sIn,rPos+1,sOut,oPos+2);
    ///Exclude
    SubSequence(sIn,rPos+1,sOut,oPos);
}

int main(){
    char str[]="abc",sOut[100];
    SubSequence(str,0,sOut,0);
}
