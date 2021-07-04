#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int v;
    list<int> *adjList;
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
        void topological_helper(int src,vector<bool>&visited,deque<int>&q)
        {
            visited[src] = true;
            for(auto nbr:adjList[src])
                if(!visited[nbr])
                    topological_helper(nbr, visited,q);
            q.push_front(src);
            return;
        }
        void topologicalSortUsingDFS()
        {
            vector<bool> visited(v, false);
            deque<int>q;
            for(int i = 0; i < v; i++)
            {
                if(!visited[i])
                    topological_helper(i, visited,q);
            }
            while(!q.empty())
            {
                cout<<q.front()<<" ";
                q.pop_front();
            }
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
    g.topologicalSortUsingDFS();
}