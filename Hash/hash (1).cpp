#include <iostream>
#include <cstring>
using namespace std;

class HashNode{
public:
    string key;
    int data;
    HashNode * next;

    HashNode (string k, int d){
        key=k;
        data=d;
        next=NULL;
    }
    ~HashNode(){
        ///write here to delete the complete list
    }
};

class HashTable{
private:
    int currentsize;
    int tablesize;
    HashNode **buckets;

    int hashFn(string k){
        int ans=0;
        int power=1;
        int L=k.length();
        for (int i=0;i<L;i++){
            int last = L-1-i;
            ans +=k[last]*power;
            ans=ans%tablesize;
            power=(power*37)%tablesize;
        }
        return ans%tablesize;
    }
    void rehash(){
        int oldSize=currentsize, oldtablesize=tablesize;
        HashNode **oldBuckets=buckets;

        tablesize*=2;
        currentsize=0;
        buckets=new HashNode*[tablesize];
        for (int i=0;i<tablesize;i++) buckets[i]=NULL;

        for (int i=0;i<oldtablesize;i++){
            HashNode* t= oldBuckets[i];
            while (t!=NULL){
                Insert(t->key,t->data);
                t=t->next;
            }
            delete oldBuckets[i];
        }
        delete [] oldBuckets;
    }
public:
    HashTable(int size=7){
        currentsize=0;
        tablesize=size;
        buckets=new HashNode* [tablesize];
        for (int i=0;i<tablesize;i++) buckets[i]=NULL;
    }

    void Insert(string k, int val){
        int hv=hashFn(k);
        HashNode* n=new HashNode(k,val);
        n->next=buckets[hv];
        buckets[hv]=n;
        currentsize++;
        ///Load Factor & Rehash
        float lf=(float)currentsize/tablesize;
        if (lf>0.7){
            cout<<"Load factor:"<<lf<<endl;
            rehash();
        }
    }

    int Search (string k){
        int hv=hashFn(k);

        if (buckets[hv]!=NULL){
            HashNode *t=buckets[hv];
            while (t!=NULL){
                if (t->key==k) {
                    return t->data;
                }
                t=t->next;
            }
        }
        return -1;
    }

    void Remove (string k){
        int hv=hashFn(k);
        ///homework, from this link list delete the node
    }
};

int main(){
    HashTable ht;
    ht.Insert("Rajesh",123);
    ht.Insert("Ravi",217);
    ht.Insert("Test",145);
    ht.Insert("Test1",122);
    ht.Insert("Test2",132);
    ht.Insert("Test3",142);
    cout<<ht.Search("Test2")<<endl;
}

