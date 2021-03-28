/**
 * Problem: Next greater element to the right
 *  Input:  2 4 1 0 0 8 7 6 9
 *  Output: 4 8 8 8 8 9 9 9 -1
*/

#include<bits/stdc++.h>
using namespace std;
vector<int>ngr(int *arr,int n)
{
    stack<int>st;
    vector<int>res;
    for(int i=n-1;i>=0;i--)
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

    vector<int> res;
    stack<int> s;
    for(int i = 0; i < n-1; i++)
    {
        bool found = false;
        for (int j = i; j < n; j++)
        {
            if(arr[j]>arr[i])
            {
                res.push_back(arr[j]);
                found = true;
                break;
            }
        }
        if(!found)
            res.push_back(-1);
    }
    res.push_back(-1);

    for(auto it:res)
        cout << it << " ";
}