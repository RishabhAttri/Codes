#include<iostream>
#include<vector>
using namespace std;

class PriorityQueue{
private:
    vector<int> v;
public:
    PriorityQueue(){
        v.push_back(-1);
    }
    void push(int d){
        v.push_back(d);
        int child=v.size()-1;
        int parent=child/2;
        while (child>1 && v[parent]>v[child]){
            swap(v[parent],v[child]);
            child=parent;
            parent=child/2;
        }
    }
    int size(){
        return v.size()-1;
    }
    int top(){
        if (v.size()>1) return v[1]; else return -1;
    }
    void pop(){
        if (v.size()<=1) return;
        v[1]=v[v.size()-1];
        v.pop_back();
        heapify(1);
    }
    void heapify(int ind){
        if (ind>v.size()) return;

        int left=2*ind;
        int right=2*ind+1;

        int min_data_index=ind;
        if (left<v.size() && v[left]<v[min_data_index])
            min_data_index=left;
        if (right<v.size() && v[right]<v[min_data_index])
            min_data_index=right;
        if (ind!=min_data_index){
            swap(v[min_data_index],v[ind]);
            heapify(min_data_index);
        }
    }
    bool isEmpty(){
        if (v.size()>1) return false; else return true;
    }

    void print(){
        for (int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    PriorityQueue pq;
    int arr[]={13,5,8,12,14,9,10};
    for (int i=0;i<7;i++) pq.push(arr[i]);
    pq.print();
    while (!pq.isEmpty()){
        int d=pq.top();
        cout<<d<<" ";
        pq.pop();
    }
}
