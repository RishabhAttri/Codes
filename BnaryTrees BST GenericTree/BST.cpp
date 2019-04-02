#include<iostream>
#include <queue>
#include<cmath>
using namespace std;

class TreeNode{
	int data;
	TreeNode* left;
	TreeNode* right;
public:
	TreeNode(int d=0):data(d),left(NULL),right(NULL){}
	friend class BST;
};

class BST{
	TreeNode* root;
public:
	BST(){
		root=NULL;
	}

	void LevelOrderPrint(TreeNode* sNode){
		queue<TreeNode*> q;

		q.push(sNode);
		q.push (NULL);

		while(!q.empty()){
			TreeNode* f=q.front();
			q.pop();

			if (f==NULL){
				cout<<endl;
				if(!q.empty()) q.push(NULL);
			}
			else{
				cout<<f->data<<" ";
				if(f->left!=NULL){
					q.push(f->left);
				}
				if(f->right!=NULL){
					q.push(f->right);
				}
			}
		}

	}
	void printLO(){
		LevelOrderPrint(root);
	}

	void inOrderPrint(TreeNode* sNode){
		if(sNode==NULL) return;

		inOrderPrint(sNode->left);
		cout << sNode->data<<" ";
		inOrderPrint(sNode->right);
	}
	void preOrderPrint(TreeNode* sNode){
		if(sNode==NULL) return;

		cout << sNode->data<<" ";
		preOrderPrint(sNode->left);
		preOrderPrint(sNode->right);
	}
	void postOrderPrint(TreeNode* sNode){
		if(sNode==NULL) return;

		postOrderPrint(sNode->left);
		postOrderPrint(sNode->right);
		cout << sNode->data<<" ";
	}
	void print (string str){
		if (str=="inorder") inOrderPrint(root);
		else if (str=="preorder") preOrderPrint(root);
		else if(str=="postorder") postOrderPrint(root);
		else LevelOrderPrint(root);
	}

	TreeNode* BuildTree_Pre_in(int preorder[],int prefm, int preto,
                            int inorder[],int infm, int into){
        if (prefm>preto) return NULL;
        int rtVal=preorder[prefm];
        TreeNode* rt=new TreeNode(rtVal);
        int i;
        for (i=infm;i<=into;i++){
            if (inorder[i]==rtVal) break;
        }
        i=i-infm;
        rt->left=BuildTree_Pre_in(preorder,prefm+1,prefm+i,inorder,infm,infm+i-1);
        rt->right=BuildTree_Pre_in(preorder,prefm+i+1,preto,inorder,infm+i+1,into);
        return rt;
    }

	void BuildTree_Pre_in(){
        int inorder[]={1, 10, 4, 6,7, 8, 3, 13, 14};
        int preorder[]={8, 10, 1, 6, 4, 7, 3, 14, 13};
        root=BuildTree_Pre_in(preorder,0,8,inorder,0,8);
	}

	TreeNode* Insert(TreeNode* rt,int d){
        if (rt==NULL){
            TreeNode *n=new TreeNode(d);
            return n;
        }
        if(d<=rt->data){
            rt->left=Insert(rt->left,d);
        } else {
            rt->right=Insert(rt->right,d);
        }
        return rt;
	}

	void TakeInput(){
	    int n;
	    cin>>n;
	    for (int i=0;i<n;i++){
            int d;
            cin>>d;
            root=Insert(root,d);
        }
	}

	bool Search (TreeNode* rt, int d){
        if (rt==NULL) return false;

        if (rt->data==d) return true;

        if (d<rt->data) return Search(rt->left,d);
        else return Search(rt->right,d);

	}

	bool Search (int d){
        return Search(root,d);
	}

	void PrintKK(TreeNode *rt, int k1, int k2){
        if (rt==NULL) return;
        if (rt->data>=k1 && rt->data<=k2){
            cout<<rt->data<<", ";
        }
        if (k1<=rt->data) PrintKK(rt->left,k1,k2);
        if (k2>=rt->data) PrintKK(rt->right,k1,k2);
	}

	void PrintKK(int k1, int k2){
        PrintKK(root, k1, k2);
	}
    TreeNode* ArraytoBST(int arr[], int be, int en){
        if (be>en) return NULL;
        int mid =(be+en)/2;
        TreeNode* n=new TreeNode(arr[mid]);
        n->left=ArraytoBST(arr,be, mid-1);
        n->right=ArraytoBST(arr,mid+1,en);
        return n;
    }

    void ArraytoBST(){
        int arr[]={1,2,3,4,5,6,7,8};
        root=ArraytoBST(arr,0,7);
    }

    void BSTToArray(TreeNode* rt, int arr[], int &oPos){
        if (rt==NULL) return;
        BSTToArray(rt->left,arr,oPos);
        arr[oPos]=rt->data; oPos++;
        BSTToArray(rt->right, arr, oPos);
    }

    int BSTToArray(int arr[]){
        int oPos=0;
        BSTToArray(root, arr, oPos);
        return oPos;
    }

    bool isBST(TreeNode* rt, int minV=INT_MIN, int MaxV=INT_MAX){
        if (rt==NULL) return true;
        if (rt->data<minV || rt->data>MaxV) return false;
        bool isLeftBST=isBST(rt->left,minV,rt->data);
        bool isRightBST=isBST(rt->right,rt->data,MaxV);

        return isLeftBST&&isRightBST;
    }

    bool isBST(){
        return isBST(root);
    }
};

int main(){

    BST bst, bst1;

    bst.ArraytoBST();
    cout<< bst.isBST()<<endl;

    bst1.BuildTree_Pre_in();
    cout<< bst1.isBST()<<endl;

	/*BST bst;
	///bst.TakeInput();
	bst.ArraytoBST();
	bst.printLO();
	cout<<endl;
	bst.print("inorder");
	cout<<endl;

	int arr[100];
	int cnt=bst.BSTToArray(arr);
	for (int i=0;i<cnt;i++){
        cout<<arr[i]<<" ";
	}
	///bst.PrintKK(9,13);*/

	/*bst.BuildTree_Pre_in();
	bst.print("inorder");*/
}
