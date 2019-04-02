#include <iostream>
using namespace std;
#define aMacro 1000

int main(){
    int c=5;
    ///cout<<c++;
    ///cout<<++c<<endl;

    ///c+=2;//c=c+2;
    ///c%=7;

    c=0;
    if (c==0 && c++) cout<<c<<endl; else cout<<"Nothing";
    cout<<c<<endl;

    return 0;
    int iA;
    short int siB;
    char cCh;
    long int lgD;

    cout<<sizeof(iA)<<endl;
    cout<<sizeof(siB)<<endl;
    cout<<sizeof(cCh)<<endl;
    cout<<sizeof(lgD)<<endl;

        const int a=100;
    cout<<aMacro<<endl;

    cout<<100<<endl;
}
