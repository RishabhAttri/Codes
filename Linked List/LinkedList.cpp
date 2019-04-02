#include <iostream>
using namespace std;

class LinkedList;

class Node{
private:
    int data;
    Node * next;
public:
    /*Node (int d){
        data=d;
        next=NULL;
    }*/

    Node (int d): data(d), next(NULL){}
    friend class LinkedList;
    friend ostream & operator<<(ostream&os, LinkedList &LL);
};

class LinkedList{
private:
    Node * head;

    bool RecSearch (Node *root, int n){
        if (root==NULL) return false;
        if (root->data==n) return true;
        return RecSearch(root->next,n);
    }

    Node * Mid (Node * root){
        if (root==NULL || root->next==NULL) return NULL;
        Node* slow=root, *fast=root->next;
        while (fast !=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        Node * m=slow->next;
        slow->next=NULL;
        return m;
    }

    Node *MergeLists(Node * root1, Node * root2){
        if (root1==NULL) return root2;
        if (root2==NULL) return root1;
        Node * newroot;

        if (root1->data<root2->data){
            newroot=root1;
            root1->next=MergeLists(root1->next,root2);
        } else {
            newroot=root2;
            root2->next=MergeLists(root1,root2->next);
        }
        return newroot;
    }

    Node * MergeSort(Node * root){
        if (root==NULL || root->next==NULL) return root;
        Node * mid=Mid(root);
        root=MergeSort(root);
        mid=MergeSort(mid);
        return MergeLists(root,mid);
    }

public:
    LinkedList(){
        head=NULL;
    }
    void InsertAtFront(int d){
        Node* temp=new Node (d);
        if (head==NULL) {
            head=temp;
        } else {
            temp->next=head;
            head=temp;
        }
    }

    void InsertAtEnd(int d){
        if (head==NULL){
            InsertAtFront(d);
            return;
        }
        Node * temp=head;
        while (temp->next!=NULL){
            temp=temp->next;
        }
        Node* n=new Node(d);
        temp->next=n;
    }

    void InsertAtK(int d, int k){
        if (head==NULL || k==1){
            InsertAtFront(d);
            return;
        }

        Node *temp=head;
        int cnt=1;
        while (temp->next!=NULL && cnt<k-1){
            cnt++;
            temp=temp->next;
        }
        Node *n=new Node(d);
        n->next=temp->next;
        temp->next=n;
    }

    void deleteAtFront(){
        if (head==NULL) return;
        Node * temp=head;
        head=head->next;
        delete temp;
    }

    void deleteAtEnd(){
        if (head==NULL) return;
        Node * temp=head;
        if (temp->next==NULL) {
            deleteAtFront();
            return;
        }
        while (temp->next->next!=NULL){
            temp=temp->next;
        }
        delete temp->next;
        temp->next=NULL;

    }

    void deleteAtK(int k){
        if (head==NULL) return;
        if (k==1){
            deleteAtFront();
            return;
        }
        Node * temp=head;
        int cnt=1;
        while (temp->next!=NULL && cnt<k-1){
            temp=temp->next;
            cnt++;
        }
        if (temp->next!=NULL) {
            Node * del= temp->next;
            temp->next=del->next;
            delete del;
        }
    }


    int Length(){
        Node * temp=head;
        int cnt=0;
        while (temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }
    void print(){
        Node * temp=head;
        while (temp!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
        return ;
    }

    bool RecSearch (int n){
        return RecSearch(head,n);
    }

    void PrintMidNode(){
        Node * t=Mid(head);
        cout<<t->data<<endl;
    }


    void MergeSort(){
        head=MergeSort (head);
    }

    void Reverse (){
        Node * prev=NULL, *cur=head, *nxt;

        while (cur!=NULL){
            nxt=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nxt;
        }
        head=prev;
    }

    void BubbleSort (Node * SortingDone){
        if (head->next==SortingDone) return;
        Node * prev=NULL, *cur=head, *nxt;
        while (cur->next!=SortingDone){
            nxt=cur->next;
            if (cur->data>nxt->data){
                ///swap nodes
                Node * t=cur;
                if (prev==NULL) head=cur->next;
                    else prev->next=cur->next;
                cur->next=nxt->next;
                nxt->next=t;
                prev=nxt;
            } else {
                prev=cur;
                cur=cur->next;
            }
        }
        ///cout<<cur->data<<" ";
        BubbleSort(cur);
    }

    void BubbleSort(){
        if (head==NULL || head->next==NULL) return;
        BubbleSort(NULL);

    }

    Node * KReverse (Node* root,int k){
        Node *prev=NULL, *cur=root, *nxt;
        int cnt=0;

        while (cur!=NULL && cnt<k){
            nxt=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nxt;
            cnt++;
        }
        if (cur!=NULL){
            root->next=KReverse(cur,k);
        }
        return prev;
    }

    void KReverse (int k){
        head=KReverse(head,k);
    }

    void Make_Cyclic (int k){
        Node* t=head;
        Node * CycNode=NULL;
        while (t->next!=NULL){
            if (t->data==k) CycNode=t;
            t=t->next;
        }
        t->next=CycNode;
        ///cout<<"Cycle created at"<< CycNode->data<<endl;
    }

    int Detect_Cyclic(){
        Node*slow=head;
        Node*fast=head;
        bool IsCycFound=false;
        while (slow!=NULL && fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if (slow==fast){
                IsCycFound=true;
                break;
            }
        }

        if (!IsCycFound){
            return -1;
        }
        ///cout<<"First loop is over";
        slow=head;
        while (slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        return slow->data;

    }
    int CheckCyclic (int k){
        Make_Cyclic(k);
        ///print();
        return Detect_Cyclic();
    }

    friend ostream & operator<<(ostream&os, LinkedList &LL);
};

ostream & operator<<(ostream&os, LinkedList &LL){
    Node * temp=LL.head;
    while (temp!=NULL){
        os<<temp->data<<"->";
        temp=temp->next;
    }
    os<<"NULL"<<endl;
    return os;
}

int main(){
    LinkedList LL;
    LL.InsertAtFront(1);
    LL.InsertAtFront(2);
    LL.InsertAtFront(3);
    LL.InsertAtEnd(4);
    LL.InsertAtK(5,2);
    LL.InsertAtK(6,10);
    /*cout<<LL.Length()<<endl;
    LL.print();
    LL.deleteAtFront();
    LL.print();
    LL.deleteAtK(13);
    LL.print();
    //LL.deleteAtK(3);
    //LL.print();*/
    ///cout<<LL;

    ///cout<<LL.RecSearch(1)<<endl;
    ///cout<<LL.RecSearch(6)<<endl;
    ///LL.PrintMidNode();
    ///LL.MergeSort();
    ///cout<<LL;
    ///LL.Reverse();
    ///cout<<LL;
    LL.BubbleSort();
    cout<<LL;
    //LL.KReverse(4);
    //cout<<LL;

    cout<<LL.CheckCyclic(4);

}
