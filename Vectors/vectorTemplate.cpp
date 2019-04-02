#include<iostream>
using namespace std;

template <class anything>
class Vector{
private:
    anything *arr;
    int index;
    int maxsize;
public:
    Vector(int size=4){
        arr=new anything[size];
        index=0;
        maxsize=size;
    }
    ~Vector(){
        delete[] arr;
    }
    int Length(){
        return index;
    }
    int getMaxSize(){
        return maxsize;
    }
    void push_back(anything n){
        if (index==maxsize){
            anything * temp=arr;
            maxsize=maxsize*2;
            arr=new anything[maxsize];
            for (int i=0;i<index;i++) arr[i]=temp[i];
            delete[] temp;temp=0;
        }
        arr[index]=n;
        index++;
    }
    anything GetValue(int ind){
        if (ind<index) return arr[ind];
    }
    anything pop_back(){
        if (index==0) return -1;
        index--;
        return arr[index];
    }
    anything &operator[] (int ind){
        return arr[ind];
    }
};

template <class anything>
ostream &operator<<(ostream &os, Vector<anything> &V){
    for (int i=0;i<V.Length();i++) os<<V[i]<<" "; os<<endl;
    return os;
}

int main(){
    Vector<int> V;
    V.push_back(1);
    V.push_back(2);
    V.push_back(3);
    V.push_back(4);
    V.push_back(5);
    cout<<V[2]<<endl;
    V[2]=33;
    cout<<V.GetValue(2)<<endl;
    ///cout<<V.GetValue(2)<<endl;
    ///cout<<V.GetValue(4)<<endl;
    cout<<V;


    Vector<char> Vchar;
    Vchar.push_back('a');
    Vchar.push_back('b');
    Vchar.push_back('c');
    Vchar.push_back('d');
    cout<<Vchar;
}
