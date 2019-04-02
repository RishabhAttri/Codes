#include<iostream>
using namespace std;

class Node{
private:
    int data;
    Node * next;
public:
    Node (int d): data(d), next(NULL){}
    ~Node(){
        if (next!=NULL) delete next;
    }
    friend class Stack;

};

class Stack{
private:
    Node* head;
public:
    Stack(){
        head=NULL;
    }
    ~Stack(){
        if (head!=NULL) delete head;
    }
    void push(int d){
        Node *n=new Node(d);
        n->next=head;
        head=n;
    }

    int top(){
        if (head==NULL) return -1; else return head->data;
    }

    void pop(){
        if (head==NULL) return;
        Node * t=head;
        head=head->next;
        t->next=NULL;
        delete t;
    }

    bool isEmpty(){
        if (head==NULL) return true; else return false;
    }
};

int main(){
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    cout<<st.top()<<endl;
    cout<<st.top()<<endl;
    st.pop();
    st.push(4);
    ///cout<<st.top()<<endl;
    ///st.pop();
    Stack st1=st;
    while (!st1.isEmpty()){
        cout<<st1.top()<<endl;
        st1.pop();
    }

}
