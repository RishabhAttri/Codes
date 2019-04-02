#include<iostream>
using namespace std;

int length(char* str){
    int i,len;
    for (i=0,len=0;str[i]!='\0';i++,len++);
    return len;
}

int main(){
    char str[100];
    cin.getline(str,100);
    cout<<length(str)<<endl;

    int s=0,e=length(str)-1;

    while (s<e){
        if (str[s]!=str[e]){
            cout<<"Not a Palin....";
            return 0;
        }
        s++;e--;
    }
    cout<<"it is a Palin.....";
}
