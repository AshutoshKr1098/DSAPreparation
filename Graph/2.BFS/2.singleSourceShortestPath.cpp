/**
 * Graph Representation using AdjancencyList (Will be using array of list)
 * Graph will be unweighted in nature, and will only store integers
*/
#include<bits/stdc++.h>
using namespace std;
class Graph
{
    int v;
    list<int> *adjList;

public:
    Graph(int n)
    {
        this->v = n;
        adjList = new list<int>[n];
    }
    void addEdge(int u,int v,bool bidir=false)
    {
        adjList[u].push_back(v);
        if(bidir)
            adjList[v].push_back(u);
        return;
    }
    void bfs(int src)
    {
        queue<int> q;
        bool *visited = new bool[v];
        q.push(src);
        visited[src] = true;
        while(!q.empty())
        {
            int currNode = q.front();
            q.pop();
            cout << currNode << " ";
            for(auto nbr:adjList[currNode])
            {
                if(!visited[nbr])
                {
                    visited[nbr] = true;
                    q.push(nbr);
                }
            }
        }
        return;
    }
    void sssp(int src,int dest)
    {
        //We don't require any visited boolean array here, since that work is taken care by distance array
        queue<int> q;
        vector<int> parent(v);
        for (int i = 0;i<parent.size();i++)
            parent[i] = i;
        vector<int> distance(v);
        for(int i = 0; i < distance.size();i++)
            distance[i] = -1;
        q.push(src);
        parent[src] = src;
        distance[src] = 0;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto nbr:adjList[node])
            {
                if(distance[nbr]==-1)
                {
                    distance[nbr] = distance[node] + 1;
                    parent[nbr] = node;
                    q.push(nbr);
                }
            }
        }

        //Following the approach to traverse from child to parent
        int child = dest;
        int par = parent[dest];
        cout<<child << "<-";
        while(parent[child]!=child)
        {
            cout << parent[child] << "<-";
            child = parent[child];
        }
        return;
    }
    void displayGraph()
    {
        for (int i = 0; i <v;i++)
        {
            cout << i << "->";
            for(auto it:adjList[i])
                cout << it << "->";
            cout << endl;
        }
    }
};

int main()
{
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(2, 4);
    g.addEdge(3, 1);
    g.addEdge(0, 4);
    g.displayGraph();
    g.bfs(1);
    return 0;
}
