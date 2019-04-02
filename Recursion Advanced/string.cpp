#include <iostream>
#include <cstring>
using namespace std;

int main(){
    string s="Rajesh", s1="Sachdev";
    cout<<s<<endl;
    cout<<s.length()<<endl;

    string sArr[5]={"Rajesh","Ravi","Ramesh","Suresh","Karunesh"};
    cout<<sArr[2]<<endl;

    string s2=s+" "+s1;
    cout<<s2<<endl;

    cout<<s[5];
    if (s[6]=='\0') cout<<"WOW";

}
