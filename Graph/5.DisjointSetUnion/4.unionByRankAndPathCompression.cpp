/**
 * Algorithm: [ Union By Rank and Path Compression ]
 * TimeComplexity: Union ( O(logn) per union in worst case of find operation,as union requires find opr to be called)
 *                 Find  ( O(logn) per find in worst case, since now we are making sure that smaller tree goes inside larger one)
 * Therefore for N operations, we will have O(nlogn) as union and O(nlogn) as find.
 * We can further improve this algorithm by Compressing the Path.
*/
#include<bits/stdc++.h>
using namespace std;

class dsu
{
    //This will store the id of individual elements
    vector<int> ds;
    vector<int>sz;
    public:
        dsu(int n)
        {
            //Initialized the vector, where each element is connected just to itself ds[i]=i and size of each component is 1
            for (int i = 0; i < n;i++)
            {
                ds.push_back(i);
                sz.push_back(1);
            }
        }
        //Returns the root of each element in their respective component
        int find(int u)
        {
            //We have a ds array in this class, where each element has the parent element stored.
            //Now we are compressing the path, by pointing making the root element as parent of node mid way,
            //while traversing from node to root
            //This will just flatten the path
            while(u!=ds[u])
            {
                ds[u] = ds[ds[u]];
                u = ds[u];
            }
            return u;
        }
        //Fetches the root of both elements and returns whether they match or not
        bool isConnected(int u,int v)
        {
            int root_u = find(u);
            int root_v = find(v);            
            return root_u == root_v;
        }
        //Performs Union Operations for given two elements
        void unionElements(int u,int v)
        {
            /*To union elements, we first find whether they are connected or not
               Then we find the root of both components and assign one component as child to other
               Note: Earlier it was the case that the LARGET SUBTREE could become a CHILD of SMALLER subtree
               Thus we further improved the union operation to always append the smaller subtree to larger one
               by taking help of sz array, which keeps track of number of elements in each component
            */            
            if(!isConnected(u,v))
            {
                int root_u = find(u);
                int root_v = find(v);
                if(sz[u]<sz[v]) //If so then connect u to v, and now size of v component +=size of incoming u component
                {
                    ds[root_u]=root_v;
                    sz[root_v] += sz[root_u];
                }
                else //or vice versa
                {
                    ds[root_v] = root_u;
                    sz[root_u] += sz[root_v];
                }
            }
        }
};
int main()
{
    dsu dis(8);
    int n;
    cin >> n;
    for (int i = 0; i < n;i++)
    {
        int u, v,q;
        cin >> u >> v>>q;
        if(q==1)
            dis.unionElements(u, v);
        else if(q==2)
        {
            if(dis.isConnected(u,v))
                cout << u << " " << v << " are connected" << endl;
            else
               cout << u << " " << v << " are not connected" << endl; 
        }
    }
}