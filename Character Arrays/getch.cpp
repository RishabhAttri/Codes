#include<iostream>
using namespace std;

int main(){
    char ch; int cnt=0;

    while (true){
        ch=cin.get();
        if (ch=='$') break;
        cnt++;
    }

    cout<<cnt;

}

/*
int main(){
    char ch; int cnt=0;

    ch=cin.get();
    while (ch!='$'){
        ch=cin.get();
        cnt++;
    }

    cout<<cnt;

}
*/
