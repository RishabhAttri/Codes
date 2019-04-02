#include <iostream>
#include <cstring>
using namespace std;

void TOH (int n, char fmT, char toT, char uT){
    if (n==0) return;

    TOH (n-1,fmT, uT, toT);
    cout<<"Move ring#"<<n<<" fm "<<fmT<<" to "<<toT<<endl;
    TOH(n-1,uT,toT,fmT);
}

int main(){
    TOH(4,'A','C','B');
}
