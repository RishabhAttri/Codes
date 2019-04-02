#include<iostream>
using namespace std;

int main(){
    char ch;
    int CharCount=0, WordCount=0, LineCount=0;
    bool isWordStarted=false;

    while (true){
        ch=cin.get();
        if (ch=='$') break;
        CharCount++;
        if (ch!=' ' && ch!='.' && ch!='\n') isWordStarted = true;

        if (ch==' '){
            if (isWordStarted) {
                WordCount++; isWordStarted=false;
            }
        }
        if (ch=='.'||ch=='\n'){
            if (isWordStarted){
                WordCount++;
                LineCount++;
                isWordStarted=false;
            }
        }
    }
    if (isWordStarted){WordCount++;LineCount++;}
    cout<<"Char:"<<CharCount<<" WordCount:"<<WordCount<<" LineCount:"<<LineCount;

}
