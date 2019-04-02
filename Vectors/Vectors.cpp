#include<iostream>
using namespace std;

class Vector{
private:
    int *arr;
    int index;
    int maxsize;
public:
    Vector(int size=4){
        arr=new int[size];
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
    void push_back(int n){
        if (index==maxsize){
            int * temp=arr;
            maxsize=maxsize*2;
            arr=new int[maxsize];
            for (int i=0;i<index;i++) arr[i]=temp[i];
            delete[] temp;temp=0;
        }
        arr[index]=n;
        index++;
    }
    int GetValue(int ind){
        if (ind<index) return arr[ind];
    }
    int pop_back(){
        if (index==0) return -1;
        index--;
        return arr[index];
    }
    int &operator[] (int ind){
        return arr[ind];
    }
};

ostream &operator<<(ostream &os, Vector &V){
    for (int i=0;i<V.Length();i++) os<<V[i]<<" "; os<<endl;
    return os;
}

int main(){
    Vector V;
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
}
