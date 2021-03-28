/**
 * Problem: Previous greater element to the left
 *  Input:  2 4 1 0 0 8 7 6 9
 *  Output: -1 -1 4 1 1 -1 8 7 -1
*/

#include<bits/stdc++.h>
using namespace std;
vector<int>pgl(int *arr,int n)
{
    vector<int> res;
    stack<int> st;
    for(int i=0;i<n;i++)
    {
        if(st.empty())
        {
            res.push_back(-1);
            st.push(arr[i]);
        }
        else if(st.top()>arr[i])
        {
            res.push_back(st.top());
            st.push(arr[i]);
        }
        else
        {
            while(!st.empty() && st.top()<=arr[i])
                st.pop();
            if(st.empty())
            {
                res.push_back(-1);
                st.push(arr[i]);
            }
            else
            {
                res.push_back(st.top());
                st.push(arr[i]);
            }
        }
    }
    return res;
}
int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    vector<int> res = pgl(arr, n);
    for(auto it:res)
        cout << it << " ";
    return 0;
}