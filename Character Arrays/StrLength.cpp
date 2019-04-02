#include<iostream>
using namespace std;

int main(){
    char str[100];
    cin.getline(str,100);
    int i,len;
    for (i=0,len=0;str[i]!='\0';i++,len++);

    cout<<len;

}
