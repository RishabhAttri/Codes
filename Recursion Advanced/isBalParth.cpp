#include <iostream>
#include <cstring>
using namespace std;

bool IsBalanced(char InStr[], int readPos, char brackets[], int bPos){
    if (InStr[readPos]=='\0'){
        if (bPos==0) return true; else return false;
        ///return !bPos;
    }

    if (InStr[readPos]=='('||InStr[readPos]=='{'||InStr[readPos]=='['){
        brackets[bPos]=InStr[readPos];
        return IsBalanced(InStr,readPos+1,brackets,bPos+1);
    } else
    if (InStr[readPos]==')'||InStr[readPos]=='}'||InStr[readPos]==']'){
        if (bPos==0) return false;
        if (InStr[readPos]==')' && brackets[bPos-1]!='(') return false;
        if (InStr[readPos]=='}' && brackets[bPos-1]!='{') return false;
        if (InStr[readPos]==']' && brackets[bPos-1]!='[') return false;
        return IsBalanced(InStr,readPos+1,brackets,bPos-1);
    } else
    return IsBalanced(InStr,readPos+1,brackets,bPos);

}

int main(){
    char str[]="[(a+b)+(c+d)]+1";
    char brackets[100];
    cout<< IsBalanced(str,0,brackets,0);
}

