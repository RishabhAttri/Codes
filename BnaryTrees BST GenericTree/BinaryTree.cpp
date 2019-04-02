#include<iostream>
#include <queue>
#include<cmath>
#include<list>
using namespace std;

class TreeNode{
	int data;
	TreeNode* left;
	TreeNode* right;
public:
	TreeNode(int d=0):data(d),left(NULL),right(NULL){}
	friend class BinaryTree;
	int show(){
	return data;
	}
	void give(int d){data=d;left=NULL;right=NULL;}
};
int NoElements(queue<TreeNode*>);
class BinaryTree{
	TreeNode* root;
public:
	BinaryTree(){
		root=NULL;
	}
    reeNode * PreInput(TreeNode * rt){
	    int i;
	    cin>>i;
	    rt=new TreeNode(i);
	    string str;
	    cin>>str;
	    if(str=="true")
	        rt->left=PreInput(rt->left);
	    cin>>str;
	    if(str=="true")
	        rt->right=PreInput(rt->right);
	    return rt;
	}
	void PreInput(){
	    root=PreInput(root);
	}
	TreeNode* levelOrderInput(){
		int d; cin>>d;
		queue<TreeNode*> q;

		TreeNode* n=new TreeNode(d);
		q.push(n);
		while (!q.empty()){
			TreeNode* f=q.front();
			q.pop();

			int ld,rd;
			cin>>ld>>rd;
			if(ld!=-1){
				f->left=new TreeNode(ld);
				q.push(f->left);
			}
			if(rd!=-1){
				f->right=new TreeNode(rd);
				q.push(f->right);
			}
		}
		return n;
	}

	void takeLOInput(){
		root=levelOrderInput();
	}
    void PreOrder(TreeNode * rt){
        if(rt==NULL/*||rt->Left==NULL*/)return;
        cout<<rt->show()<<" ";
        PreOrder(rt->left);
        PreOrder(rt->right);
    }
    void PreOrder(){
        PreOrder(root);
    }
    int Sum(TreeNode * rt){
        static int s;
        if(rt==NULL)return s;
        s+=rt->data;
        Sum(rt->left);
        Sum(rt->right);
    }
    void Sum(){
        cout<<Sum(root);
    }
    int Depth(TreeNode * rt){
        static int n;int L=-1;
        if(rt==NULL)return 0;
        if(rt->left==NULL&& rt->right==NULL)return n+1;
        if(rt->left==NULL)L=1;
        if(rt->right==NULL)L=0;
        n++;
        if(L==-1){
            int depL=Depth(rt->left);
            int depR=Depth(rt->right);
            n--;
            return max(depL,depR);
        }
        if(L==0){
            int depL=Depth(rt->left);
            n--;
            return depL;
        }
        if(L==1){
            int depR=Depth(rt->right);
            n--;
            return depR;
        }
    }
    bool Iden(TreeNode * rt){
        if(rt==NULL){return true;}
        if(abs(Depth(rt->left)-Depth(rt->right))<=1){
            if(Iden(rt->right) && Iden(rt->left)){
                return true;
            }
             return false;
        }

         return false;
    }
    void Depth(){
        cout<<Depth(root->left->left);
    }
    void identical(){
        cout<<Iden(root);
    }
    list<TreeNode*>* BTtoMLLClass(){
        list<TreeNode*> l[10];
        cout<<"a ";
        l[0].push_back(root);
        cout<<"a1 ";
        int i=0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            cout<<"L ";
            TreeNode *f=q.front();
            q.pop();
            if(q.empty())i++;
            if(f->left!=NULL){l[i].push_back(f->left);q.push(f->left);}
            if(f->right!=NULL){l[i].push_back(f->right);q.push(f->right);}
        }
        return l;
    }
    list<int>* BTtoMLLData(){
    list<int> l[10];
        cout<<"a ";
        l[0].push_back(root->data);
        cout<<"a1 ";
        int i=0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            cout<<"L ";int k=0;
            TreeNode *f=q.front();
            if(k==0 || k==2)
            if(NoElements(q)%2==0)i++;
            if(k==1)
            if(NoElements(q)%2!=0)i++;

            q.pop();
            if(f->left!=NULL){l[i].push_back(f->left->data);q.push(f->left);}
            if(f->right!=NULL){l[i].push_back(f->right->data);q.push(f->right);}\
            if(f->right==NULL)k++;
            if(f->left==NULL)k++;

        }
        return l;
    }
    void NoSiblings(TreeNode *rt){
        if(rt->right==NULL && rt->left ==NULL){cout<<rt->data<<" ";return;}
        if(rt->left!=NULL)
        NoSiblings(rt->left);
        if(rt->right!=NULL)
        NoSiblings(rt->right);
    }
    void NoSiblings(){
        NoSiblings(root);
    }
    void levelOrderOutput(){
        cout<<root->data<<endl;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* f= q.front();int k=0;
            q.pop();
            if(k==0 || k==2)
            if(NoElements(q)%2==0)cout<<endl;
            if(k==1)
            if(NoElements(q)%2!=0)cout<<endl;
            if(f->left!=NULL){cout<<f->left->data<<" ";q.push(f->left);}
            if(f->right!=NULL){cout<<f->right->data<<" ";q.push(f->right);}
            if(f->left==NULL)k++;
            if(f->right==NULL)k++;
        }
    }
    TreeNode * InAndPre(int In[],int *Pre,int ns,int ne,TreeNode * rt){
        if(ns>=ne)return rt;
        int i;
        rt=new TreeNode;
        rt->give(Pre[0]);
        for(i=ns;i<ne;i++)if(In[i]==Pre[0])break;
        InAndPre(In,Pre+1,ns,i,rt->left);
        InAndPre(In,Pre+i+1,i+1,ne,rt->right);
        return rt;
    }
    void InAndPre(int In[],int Pre[],int n1){
        TreeNode * n;
        root=InAndPre(In,Pre,0,n1,n);
    }
};
int NoElements(queue<TreeNode*> q){
    int i=0;
    while(q.empty()){
        q.pop();
        i++;
    }
    return i;
}




int main(){

	BinaryTree BT;
	BT.takeLOInput();
	BT.PreOrder();
	BT.Sum();cout<<" ";
	BT.Depth();cout<<" ";
	BT.identical();
	/*list<int> *mylist,ll[10];
	    mylist=new list<int>;
	mylist=ll;
	mylist=BT.BTtoMLLData();
	for(int i=0;i<3;i++,mylist++){
    for(list<int>::iterator iter = mylist->begin(); iter != mylist->end(); iter++){
        cout<<*iter<<endl;
    }
    cout<<endl;
	}
	for(int i=0;i<3;i++){
    for(list<int>::iterator iter = ll[i].begin(); iter != ll[i].end(); iter++){
        cout<<*iter<<endl;
    }
    cout<<endl;
	}*/
    cout<<endl;
	BT.NoSiblings();cout<<endl;
	cout<<endl<<endl;
    BT.levelOrderOutput();
    BinaryTree BT1;
    int n;cin>>n;
    int In[100],Pre[100];
    cout<<"Inorder ";
    for(int i=0;i<n;i++)cin>>In[i];
    cout<<"Preorder ";
    for(int i=0;i<n;i++)cin>>Pre[i];
    BT1.InAndPre(In,Pre,n);
    BT1.PreOrder();
}
