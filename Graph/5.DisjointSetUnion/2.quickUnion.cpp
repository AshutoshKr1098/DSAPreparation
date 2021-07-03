/**
 * Algorithm: [ Quick Union]
 * TimeComplexity: Union ( O(n) per union in worst case of find operation,as union requires find opr to be called)
 *                 Find  ( O(n) per find in worst case of skewed tree)
 * Therefore for N operations, we will have O(n2) as union and O(n) as find.
 * Find operation can become very time consuming if the tree keeps getting skewed, so we need to move to a better approach
*/
#include<bits/stdc++.h>
using namespace std;

class dsu
{
    //This will store the id of individual elements
    vector<int> ds;
    public:
        dsu(int n)
        {
            //Initialized the vector, where each element is connected just to itself ds[i]=i
            for (int i = 0; i < n;i++)
                ds.push_back(i);
        }
        //Returns the root of each element in their respective component
        int find(int u)
        {
            //We have a ds array in this class, where each element has the parent element stored.
            while(u!=ds[u])
                u = ds[u];
            return ds[u];
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
               Note: Here it might be the case that the LARGET SUBTREE can become a CHILD of SMALLER subtree
               Thus we will further improve the union operation to always append the smaller subtree to larger one
            */            
            if(!isConnected(u,v))
            {
                int root_u = find(u);
                int root_v = find(v);
                ds[root_v]=root_u;                
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