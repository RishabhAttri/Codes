#include<iostream>
using namespace std;

class Queue{
private:
    int *arr;
    int currentSize;
    int maxSize;
    int front;
    int rear;
public:
    Queue(int n=4){
        maxSize=n;
        arr=new int[maxSize];
        currentSize=0;
        front=0;
        rear=maxSize-1;
    }
    void push(int d){
        if (currentSize<maxSize){
            rear=(rear+1)%maxSize;
            arr[rear]=d;
            currentSize++;
        }
    }

    int getFront(){
        if (currentSize==0) return -1; else return arr[front];
    }

    void pop(){
        if (currentSize>0){
            front=(front+1)%maxSize;
            currentSize--;
        }
    }

    bool isEmpty(){
        if (currentSize==0) return true; else return false;
    }
};


int main(){
    Queue Q(4);
    Q.push(1);
    Q.push(2);
    Q.push(3);
    Q.push(4);
    cout<<Q.getFront()<<endl;
    Q.pop();
    Q.push(5);
    cout<<endl;
    while (!Q.isEmpty()){
        cout<<Q.getFront()<<endl;
        Q.pop();
    }
}
