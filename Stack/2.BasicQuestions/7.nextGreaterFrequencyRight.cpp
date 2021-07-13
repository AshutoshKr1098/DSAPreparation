/**
 * Problem: Next greater frequency element to the right
 *  Input:  1 1 2 3 4 2 1 4 3 5 5 5 5 5
 *  Output: 5 5 1 1 1 1 5 5 5 -1 -1 -1 -1 -1 
*/

#include<bits/stdc++.h>
using namespace std;

vector<int>ngfr(int *arr,int n)
{
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++)
        mp[arr[i]]++;
    vector<int>res;
    stack<pair<int,int>>st;
    for(int i=n-1;i>=0;i--)
    {
        if(st.empty())
        {
            res.push_back(-1);
            st.push({arr[i],mp[arr[i]]});
        }
        else
        {
            while(!st.empty() && st.top().second<=mp[arr[i]])
                st.pop();
            if(st.empty())
            {
                res.push_back(-1);
                st.push({arr[i],mp[arr[i]]});
            }
            else
            {
                res.push_back(st.top().first);
                st.push({arr[i],mp[arr[i]]});
            }
        }
    }
    reverse(res.begin(),res.end());
    return res;
}
int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    vector<int>res=ngfr(arr,n);
    for(auto it:res)
        cout<<it<<" ";
    cout<<endl;
    return 0;
}