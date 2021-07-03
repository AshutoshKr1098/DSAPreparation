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
    void dfsHelper(int src,vector<bool>&visited)
    {
        visited[src] = true;
        cout << src << " ";
        for(auto nbr:adjList[src])
        {
            if(!visited[nbr])
                dfsHelper(nbr,visited);
        }
        return;
    }
    void dfs()
    {
        vector<bool> visited(v,false);
        for (int i = 0; i < v;i++)
        {
            if(!visited[i])
            {
                dfsHelper(i, visited);
            }
        }
        return;
    }
    void dfsIterative(int src,vector<bool>&visited)
    {
        stack<int> st;
        st.push(src);
        visited[src] = true;
        while (!st.empty())
        {
            int node = st.top();
            st.pop();
            cout << node << " ";
            for (auto nbr : adjList[node])
            {
                if(!visited[nbr])
                {
                    visited[nbr] = true;
                    st.push(nbr);
                }
            }
        }
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
    g.dfs();
    return 0;
}
