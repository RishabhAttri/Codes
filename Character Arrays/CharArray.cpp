#include<iostream>
using namespace std;

int main(){
    char ch[5]={'a','e','i','o','u'};

    for (int i=0;i<5;i++) cout<<ch[i]<<" "; cout<<endl;
    cout<<sizeof(ch)<<endl;

    char str[]="Rajesh";
    cout<<sizeof(str)<<endl;

    cout<<ch<<endl;
    cout<<str<<endl;

    char str1[100];
    cin.getline (str1,100);
    cout<<str1<<endl;

    cin.getline(str1,100,'$');
    cout<<str1<<endl;

    cin.get();

    str1="Ravi";
}
