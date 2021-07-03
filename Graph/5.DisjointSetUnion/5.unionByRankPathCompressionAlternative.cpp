/**Disjoint Set: Union By rank and Path Compression*/

#include<bits/stdc++.h>
using namespace std;

class dsu
{
    int *root;
    int *rank;
    //constructor function to initialize the root array of each element and rank of each element
    dsu(int n)
    {
        root=new int[n];
        for(int i=0;i<n;i++)
        {
            root[i]=i;
            rank[i]=0;
        }
    }

    int find(int u)
    {
        while(u!=root[u])
        {
            //Initially root[u] contained parent of u, now it will contain parent of parent of u, thus we go on compressing each element to it's 
            //grandparent, (ultimately leading every element to point to a single root element)

            //This step is called path compression, and thus we limit ourself to a very less depth tree structure
            root[u]=root[root[u]];
            u=root[u];
        }
        return u;
    }

    void unionByRank(int u,int v)
    {
        int root_u = find(u);
        int root_v = find(v);

        if(root_u != root_v)
        {
            if(rank[root_u]==rank[root_v])
                rank[root_u]++; //We could also have incremented rank[v], it doesn't matter
            if(rank[root_u]>rank[root_v])
                root[root_v]=root_u;
            else
                root[root_u]=root_v;
        }
    }
};