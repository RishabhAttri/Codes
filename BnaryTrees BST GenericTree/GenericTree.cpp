#include <iostream>
#include<queue>
using namespace std;

class MyPair{
public:
    int MaxSum;
    int NodeData;

    MyPair(){
        MaxSum=0;
        NodeData=0;
    }
};

class TreeNode{
private:
    int data;
    TreeNode **children;
    int child_count;
public:
    TreeNode(int d){
        data=d;
        children=NULL;
        child_count=0;
    }
friend class GenericTree;
};

class GenericTree {
private:
    TreeNode *root;
public:
    GenericTree(){
        root=NULL;
    }

    TreeNode* takeInput(){
        int d,c;
        cout<<"enter node data:";
        cin>>d;
        TreeNode *n=new TreeNode(d);

        cout<<"enter the no of children for"<<d<<":";
        cin>>c;

        n->child_count=c;
        n->children=new TreeNode*[c];

        for (int i=0;i<c;i++){
            n->children[i]=takeInput();
        }
        return n;
    }
    void FillTree(){
        root=takeInput();
    }

    void PreOrder(TreeNode* rt){
        if (rt==NULL) return;
        cout<<rt->data<<" ";
        for (int i=0;i<rt->child_count;i++){
            PreOrder(rt->children[i]);
        }

    }
    void PrintPreOrder(){
        cout<<endl<<"Pre Order:";
        PreOrder(root);
    }
    void PostOrder(TreeNode* rt){
        if (rt==NULL) return;
        for (int i=0;i<rt->child_count;i++){
            PostOrder(rt->children[i]);
        }
        cout<<rt->data<<" ";

    }

    void PrintPostOrder(){
        cout<<endl<<"Post Order:";
        PostOrder(root);
    }

    void FillLevelOrder(){
        queue<TreeNode*> q;
        cout<<"enter root data:";
        int d; cin>>d;
        root = new TreeNode (d);
        q.push(root);
        while (!q.empty()){
            TreeNode* f=q.front();
            q.pop();
            cout<<"enter count of children for"<<f->data<<":";
            int c; cin>>c;
            f->child_count=c;
            f->children=new TreeNode*[c];
            for (int i=0;i<c;i++){
                cout<<"Enter data for child#"<<i<<"of node "<<f->data<<":";
                cin>>d;
                f->children[i]=new TreeNode(d);
                q.push(f->children[i]);
            }
        }
    }

    void PrintLevelOrder(){
        if (root==NULL) return;
        cout<<endl<<"Level Order Print:"<<endl;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);

        while (!q.empty()){
            TreeNode* f=q.front();
            q.pop();
            if (f==NULL){
                cout<<endl;
                if (!q.empty()) q.push(NULL);
            } else {
                cout<<f->data<<" ";
                for (int i=0;i<f->child_count;i++){
                    q.push(f->children[i]);
                }
            }
        }

    }

    int GetSum(TreeNode* rt){
        if (rt==NULL) return 0;

        int sum=rt->data;
        for (int i=0;i<rt->child_count;i++){
            sum+=GetSum(rt->children[i]);
        }
        return sum;
    }
    int GetSum(){
        return GetSum(root);
    }

    int GetCount(TreeNode* rt){
        if (rt==NULL) return 0;

        int cnt=1;
        for (int i=0;i<rt->child_count;i++){
            cnt+=GetCount(rt->children[i]);
        }
        return cnt;
    }
    int GetCount(){
        return GetCount(root);
    }

    int GetMax(TreeNode* rt){
        if (rt==NULL) return 0;

        int Max=rt->data;
        for (int i=0;i<rt->child_count;i++){
            int cMax=GetMax(rt->children[i]);
            if (cMax>Max) Max=cMax;
        }
        return Max;
    }
    int GetMax(){
        return GetMax(root);
    }

    int GetHeight(TreeNode * rt){
        if (rt==NULL) return 0;
        int h=0;
        for (int i=0;i<rt->child_count;i++){
            int cHeight=GetHeight(rt->children[i]);
            h=max(h,cHeight);
        }
        return h+1;
    }

    int GetHeight(){
        return GetHeight(root);
    }

    void PrintAtK (int k, TreeNode* rt, int Level){
        if (rt==NULL) return;
        if (Level==k) cout<<rt->data<<" ";

        for (int i=0;i<rt->child_count;i++){
            PrintAtK (k,rt->children[i], Level+1);
        }

    }

    void PrintAtK(int k){
        PrintAtK (k,root,1);
    }

    int CountMoreThanK(int k, TreeNode* rt){
        if (rt==NULL) return 0;
        int cnt=0;
        if (rt->data>k) cnt++;
        for (int i=0;i<rt->child_count;i++){
            cnt+=CountMoreThanK(k,rt->children[i]);
        }
        return cnt;
    }

    int CountMoreThanK(int k){
        return CountMoreThanK (k,root);
    }

    MyPair MaxSum (TreeNode* rt){
        MyPair p;
        if (rt==NULL) return p;

        int mySum=rt->data;
        for (int i=0;i<rt->child_count;i++){
            mySum+=rt->children[i]->data;
        }
        p.NodeData=rt->data;
        p.MaxSum=mySum;
        MyPair cp;
        for (int i=0;i<rt->child_count;i++){
            cp=MaxSum(rt->children[i]);
            if (cp.MaxSum>p.MaxSum) p=cp;
        }
        return p;

    }
    MyPair MaxSum (){
        return MaxSum (root);
    }

};

int main(){
    GenericTree GT;
    GT.FillTree();
    //GT.FillLevelOrder();
    GT.PrintLevelOrder();
    GT.PrintPreOrder();
    GT.PrintPostOrder();
    cout<<endl;
    cout<<"sum:"<<GT.GetSum()<<endl;
    cout<<"count:"<<GT.GetCount()<<endl;
    cout<<"Max:"<<GT.GetMax()<<endl;
    cout<<"Height:"<<GT.GetHeight()<<endl;
    GT.PrintAtK(3);
    cout<<endl;
    cout<<GT.CountMoreThanK(6)<<endl;
    MyPair p=GT.MaxSum();
    cout<<"Maximum Sum is:"<<p.MaxSum<<" which is for Node:"<<p.NodeData;

}
/*
PreOrder
1 3 2 2 5 2 9 0 10 0 6 0 3 0 4 2 7 0 8 0

LevelOrder
1 3 2 3 4 2 5 6 0 2 7 8 2 9 10 0 0 0 0 0*/
