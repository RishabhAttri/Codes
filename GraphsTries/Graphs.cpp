#include <iostream>
#include<list>
#include<queue>
using namespace std;

class Graph{
private:
    int V;
    list<int> *l;
public:
    Graph(int vertices){
        V=vertices;
        l=new list<int>[V];
    }
    ~Graph(){
        delete [] l;
    }
    void AddEdge(int fmV, int toV, bool bidir=true){
        l[fmV].push_back(toV);
        if (bidir) l[toV].push_back(fmV);
    }

    void PrintAdjList(){
        for (int i=0;i<V;i++){
            cout<<i<<"->";
            for (auto it=l[i].begin();it!=l[i].end();it++){
                cout<<*it<<", ";
            }
            cout<<endl;
        }
    }

    void bfs (int s){
        bool *visited=new bool[V];
        for (int i=0;i<V;i++) visited[i]=false;

        queue<int> q;
        q.push(s);
        visited[s]=true;

        while (!q.empty()){
            int f=q.front();
            cout<<f<<" ";
            q.pop();

            for (auto it=l[f].begin();it!=l[f].end();it++){
                if (!visited[*it]){
                    q.push(*it);
                    visited[*it]=true;
                }
            }
        }
        cout<<endl;
    }

    void bfsPath(int s, int d){
        int *distance=new int[V];
        int *parent=new int[V];
        for (int i=0;i<V;i++){
            distance[i]=-1;
            parent[i]=-1;
        }
        queue<int> q;
        q.push(s);
        distance[s]=0;

        while (!q.empty()){
            int f=q.front();
            cout<<f<<" "<<distance[f]<<endl;
            q.pop();
            for (auto it=l[f].begin();it!=l[f].end();it++){
                if (distance[*it]==-1){
                    q.push(*it);
                    distance[*it]=distance[f]+1;
                    parent[*it]=f;
                }
            }
        }
        cout<<"Distance of dest is:"<<distance[d]<<endl;
        cout<<"Path is:"<<d<<"<-";
        int p=parent[d];
        while (p!=-1){
            cout<<p<<"<-";
            p=parent[p];
        }
    }

    void dfsRecursive(int node, bool *visited){
        ///base case not required as it is already controlled

        ///Print the node
        cout<<node<<" ";
        visited[node]=true;

        ///Recursive call each child
        for (auto it=l[node].begin(); it!=l[node].end();it++){
            if (!visited[*it]){
                dfsRecursive (*it,visited);
            }
        }
    }

    void dfs (int s){
        bool* visited=new bool[V];
        for (int i=0;i<V;i++) visited[i]=false;
        dfsRecursive (s,visited);
        cout<<endl;

    }

    void dfsAllComponents(){
        bool* visited=new bool[V];
        for (int i=0;i<V;i++) visited[i]=false;
        int component=0;

        for (int i=0;i<V;i++){
            if (!visited[i]){
                component++;
                cout<<endl<<"dfs of component-"<<component<<endl;
                dfsRecursive(i,visited);
            }
        }
    }
};

int main(){
    int n=36;
    int *board=new int[n+1];
    for (int i=1;i<=n;i++) board[i]=i;
    board[2]=15;
    board[5]=7;
    board[9]=27;
    board[17]=4;
    board[18]=29;
    board[20]=6;
    board[24]=16;
    board[25]=35;
    board[32]=30;
    board[34]=12;
    Graph g (n+1);
    for (int i=1; i<n;i++){
        for (int j=1;j<=6;j++){
            if (i+j<=36){
                g.AddEdge(i,board[i+j],false);
            }
        }
    }
    g.bfsPath(1,26);
    ///g.PrintAdjList();

/*
    Graph g(10);
    g.AddEdge(1,2);
    g.AddEdge(1,3);
    g.AddEdge(2,4);
    g.AddEdge(2,5);
    g.AddEdge(3,5);
    g.AddEdge(7,8);
    g.AddEdge(7,9);
    g.AddEdge(8,9);

    g.dfsAllComponents();
    */
/*    Graph g(6);
    g.AddEdge(1,2);
    g.AddEdge(1,3);
    g.AddEdge(2,4);
    g.AddEdge(2,5);
    g.AddEdge(3,5);
    g.PrintAdjList();
    g.bfs(1);
    g.bfs(5);
    cout<<"starting BFSPath:"<<endl;
    g.bfsPath(1,4);
    cout<<"DFS Output"<<endl;
    g.dfs(1);
    g.dfs(4);
    g.dfsAllComponents();
    */
}
