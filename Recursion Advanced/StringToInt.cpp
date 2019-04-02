#include <iostream>
using namespace std;

int Convert (char str[], int CurNumber){
    if (str[0]=='\0') return CurNumber;

    int d=str[0]-'0';
    int n=CurNumber*10+d;
    return Convert(str+1,n);
}


int main(){
    char str[]="1234";
    int i=Convert(str,0);
    cout<<i;
}
