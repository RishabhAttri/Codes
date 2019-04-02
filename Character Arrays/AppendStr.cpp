#include<iostream>
using namespace std;

int length(char* str){
    int i,len;
    for (i=0,len=0;str[i]!='\0';i++,len++);
    return len;
}

void AppendStr(char *s1, char*s2){
    int l1=length(s1),i;
    for (i=0;s2[i]!='\0';i++){
        s1[l1+i]=s2[i];
    }
    s1[l1+i]='\0';
}

int main(){
    char str1[100], str2[100];

    cin.getline(str1,50);
    cin.getline(str2,50);
    AppendStr(str1,str2);
    cout<<str1<<endl;

}
