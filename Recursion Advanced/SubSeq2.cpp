#include <iostream>
#include <cstring>
using namespace std;

int SubSequence(char sIn[],int rPos, string sOut[]){
    if (sIn[rPos]=='\0'){
        sOut[0]='\0';
        return 1;
    }
    int cnt=SubSequence(sIn,rPos+1,sOut);
    for (int i=0;i<cnt;i++){
        sOut[cnt+i]=sIn[rPos]+sOut[i];
    }
    return cnt*2;
}

int main(){
    char str[]="abc";
    string sOut[100];
    int cnt=SubSequence(str,0,sOut);
    for (int i=0;i<cnt;i++) cout<<sOut[i]<<endl;
}
