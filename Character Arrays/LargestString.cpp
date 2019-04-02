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
    int n;cin>>n;cin.get();
    char str[100];

    int largest=0; char LString[100]={'\0'};
    for (int i=0;i<n;i++){
        cin.getline(str,100);
        if (length(str)>largest){
            largest=length(str);
            LString[0]='\0';
            AppendStr(LString,str);
        }
    }
    cout<<LString;

}
