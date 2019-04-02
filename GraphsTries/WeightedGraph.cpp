#include<iostream>
#include<list>
#include<queue>
using namespace std;

typedef pair<int,int> ii;

class comp{
public:

    bool operator()(ii &a, ii&b){
        return a.second>b.second;
    }

};

class Graph{
private:
    list<ii> *adjList;
    int V;
public:
    Graph (int n){
        V=n;
        adjList= new list<ii>[V+1];
    }
    void addEdge(int src, int dest, int wt){
        adjList[src].push_back(make_pair(dest,wt));
    }

    int dijikstra(int src, int dest){
        priority_queue<ii,vector<ii>,comp> pq;
        int *dist=new int[V+1];
        for (int i=0;i<=V;i++) dist[i]=10000;
        dist[src]=0;
        pq.push(make_pair(src,0));

        while (!pq.empty()){
            ii f=pq.top();
            pq.pop();
            int fDest=f.first;
            int fDist=f.second;

            if (dist[fDest]<fDist) continue;

            dist[fDest]=fDist;
            for (auto it=adjList[fDest].begin(); it!=adjList[fDest].end();it++){
                ii n=*it;
                int childDist=fDist+n.second;
                if (childDist<dist[n.first]) {
                   pq.push(make_pair(n.first,childDist));
                }
            }
        }
        ///all distances are updated;
        for (int i=1;i<=V;i++) cout<<i<<"-"<<dist[i]<<endl;
        int ans=dist[dest];
        delete [] dist;
        return ans;
    }
};

int main(){
    Graph g(6);
    g.addEdge(1,2,100);
    g.addEdge(1,3,20);
    g.addEdge(2,4,10);
    g.addEdge(3,2,75);
    g.addEdge(3,5,70);
    g.addEdge(4,6,20);
    g.addEdge(5,6,30);
    cout<<g.dijikstra(1,6);
}
