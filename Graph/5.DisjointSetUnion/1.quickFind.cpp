/**
 * Algorithm: [ Quick Find]
 * TimeComplexity: Union ( O(n) per union)
 *                 Find  ( O(1) per find)
 * Therefore for N operations, we will have O(n2) as union and O(n) as find.
 * Union operation is very time consuming, so we need to move to a better approach
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
        bool isConnected(int u,int v)
        {
            return ds[u] == ds[v];
        }
        void unionElements(int u,int v)
        {
            /*To union elements, we first find what set do they belong to 
              Then we check, if they belong to the same set, no need to union, they are already in same component
              Else if they belong to different set, we change the set v to set u ( by changing set id of EACH element of v to u)
            */
            int uid = ds[u];
            int vid = ds[v];
            if(!isConnected(uid,vid))
            {
                //then change the parent(set id) of v to u
                for (int i = 0; i < ds.size();i++)
                    if(ds[i]==vid)
                        ds[i] = uid;
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