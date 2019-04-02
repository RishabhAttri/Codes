#include<iostream>
using namespace std;

int main(){
    char ch;
    int Dgt=0,WS=0,Alpha=0,Others=0;

    while (true){
        ch=cin.get();
        if (ch=='$') break;
        if (ch>='0' && ch<='9') Dgt++;
        else if(ch==' '||ch=='\n') WS++;
        else if((ch>='A'&& ch<='Z')||(ch>='a'&& ch<='z')) Alpha++;
        else Others++;
    }
    cout<<"Dgt:"<<Dgt<<" WS:"<<WS<<" Alpha:"<<Alpha<<" Others:"<<Others;

}
