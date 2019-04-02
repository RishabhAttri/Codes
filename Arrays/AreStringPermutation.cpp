#include<iostream>
using namespace std;

int main(){
    char str1[100], str2[100];

    cin.getline(str1,100);
    cin.getline (str2,100);

    int CharCnt[256]={0},i;

    for (i=0; str1[i]!='\0'&&str2[i]!='\0';i++){
        CharCnt[str1[i]]++;
        CharCnt[str2[i]]--;
    }
    if (str1[i]!='\0'||str2[i]!='\0'){
        cout<<"Not a permutation";
        return 0;
    }

    for (int i=0;i<256;i++){
        if (CharCnt[i]!=0){
            cout<<"Not a permutation";
            return 0;
        }
    }

    cout<<"It is a Permutation";
}
