#include <iostream>
#include <cstring>
using namespace std;

void CodeToString(char InStr[], int rPos, char out[], int oPos){
    if(InStr[rPos]=='\0'){
        out[oPos]='\0';
        cout<<out<<endl;
        return;
    }
    int fNum=InStr[rPos]-'0';
    if (fNum==0)return;
    out[oPos]=fNum+'A'-1;
    CodeToString (InStr,rPos+1,out,oPos+1);

    if (InStr[rPos+1]!='\0'){
        int sNum=InStr[rPos+1]-'0';
        int Num=fNum*10+sNum;
        if (Num<=26){
            out[oPos]=Num+'A'-1;
            CodeToString (InStr,rPos+2,out,oPos+1);
        }
    }

}


int main(){
    char str[]="1103";
    char out[100];
    CodeToString(str,0,out,0);
}
