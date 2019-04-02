#include <iostream>
using namespace std;

int Convert (char str[],int &pv){
    ///base case
    if (str[0]=='\0') {
        pv=1;
        return 0;
    }
    ///recursive call
    int n= Convert(str+1,pv);
    ///back tracking tasks
    int d=str[0]-'0';
    n=n+d*pv;
    pv*=10;
    return n;
}


int main(){
    char str[]="1234";
    int pv=1;
    int i=Convert(str,pv);
    cout<<i;
}
