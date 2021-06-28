/**
 * Graph Representation: AdjancencyList using Map to store any type of graph
 * Can be used to also store the weights(which we will see in next module)
*/
#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Graph
{
    unordered_map<T, list<pair<T, int>>> um;
    public:
        void addEdge(T u, T v, int wt,bool bidir=true)
        {
            um[u].push_back({v, wt});
            if(bidir)
                um[v].push_back({u, wt});
        }
        void displayGraph()
        {
            for(auto it:um)
            {
                cout << it.first << "->";
                for(auto x:it.second)
                    cout << "(" << x.first << "," << x.second << ")->";
                cout << endl;
            }
        }
};
int main()
{
    Graph<string>g;
    g.addEdge("Delhi", "Mumbai", 40);
    g.addEdge("Delhi", "Punjab", 10);
    g.addEdge("Mumbai", "Chennai", 90);
    g.addEdge("Chennai", "Agra", 140);
    g.addEdge("Agra", "Mumbai", 60);
    g.displayGraph();
}