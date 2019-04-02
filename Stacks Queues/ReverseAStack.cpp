#include<iostream>
#include<stack>
using namespace std;

void ReverseStack(stack<int>&s, stack<int>&s1){
    if (s1.empty()) return;
    int val=s1.top();
    s1.pop();
    ReverseStack(s,s1);
    s.push(val);
}

void ReverseStack(stack<int>&s){
    stack<int> s1;
    while (!s.empty()){
        s1.push(s.top());
        s.pop();
    }
    ReverseStack(s, s1);
}

int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    ReverseStack(s);

    while (!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
}
