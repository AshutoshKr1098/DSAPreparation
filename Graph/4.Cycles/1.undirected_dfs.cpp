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
    bool cycle_helper(int src,vector<bool>&visited,int parent)
    {
        visited[src] = true;
        for(auto nbr:adjList[src])
        {
            if(!visited[nbr])
            {
                bool cycle = cycle_helper(nbr, visited, src);
                if(cycle)
                    return true;                
            }
            else if(nbr!=parent)
                return false;
        }
        return false;
    }
    bool detectCycleUsingDFS(int src)
    {
        vector<bool> visited(v, false);
        return cycle_helper(src, visited, -1);
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
    return 0;
}
