#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int v;
    list<int> *adjList;
    map<int,int>indegree;
    public:
        Graph(int v)
        {
            this->v = v;
            adjList = new list<int>[v];           
        }

        void addEdge(int u,int v,bool bidir=false)
        {
            adjList[u].push_back(v);
        }
        void displayGraph()
        {
            for (int i = 0; i < v;i++)
            {
                cout << i << "->";
                for(auto it:adjList[i])
                    cout << it << "->";
                cout << endl;
            }
        }
        void findIndegree()
        {
            for (int i = 0;i<v;i++)
            {
                if(indegree.find(i)==indegree.end())
                    indegree[i]=0;   
                for (auto it : adjList[i])
                    indegree[it]++;
            }
            for(auto x:indegree)
                cout << x.first << " " <<x.second<< endl;
        }
        void topologicalSortUsingBFS()
        {
            findIndegree();
            queue<int> q;
            for(auto it:indegree)
                if(it.second==0)
                    q.push(it.first);
            while(!q.empty())
            {
                int node = q.front();
                q.pop();
                cout << node << " ";
                for(auto nbr:adjList[node])
                {
                    indegree[nbr]--;
                    if(indegree[nbr]==0)
                        q.push(nbr);
                }
            }
            cout << endl;
            return;
        }
};

int main()
{
    Graph g(6);
    int edges;
    cin >> edges;
    int u, v;
    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v;
        g.addEdge(u, v);
    }
    g.displayGraph();
    g.topologicalSortUsingBFS();
    g.findIndegree();
}