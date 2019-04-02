#include <iostream>
#include <cstring>
using namespace std;

void Permutation (char str[], int s)
{
    if (str[s]=='\0'){
        cout<<str<<endl;
        return;
    }
    for (int i=s; str[i]!='\0';i++){
        swap(str[s],str[i]);
        Permutation(str,s+1);
        swap(str[s],str[i]);
    }
}

int main(){
    char str[]="abc";
    Permutation(str,0);
}
