#include <iostream>
using namespace std;

int main(){
    int s=0,e=300,step=20;
    int i;
    for (i=s;i<=e;i=i+20){
        float c=((float)5/9)*(i-32);
        cout<<i<<" "<<c<<endl;
    }

}
