#include<bits/stdc++.h>
using namespace std;

vector<int> ngl(int *arr,int n)
{
    vector<int> res;
    stack<int> s;
    for (int i = 0; i<n;i++)
    {
        if(s.empty())
        {
            res.push_back(-1);
            s.push(arr[i]);
        }
        else if(s.top()>arr[i])
        {
            res.push_back(s.top());
            s.push(arr[i]);
        }
        else 
        {
            while(!s.empty() && s.top()<=arr[i])
                s.pop();
            if(s.empty())
            {
                res.push_back(-1);
                s.push(arr[i]);
            }
            else if(s.top()>arr[i])
            {
                res.push_back(s.top());
                s.push(arr[i]);
            }
        }
    }    
    return res;
}
vector<int> ngr(int *arr,int n)
{
    vector<int> res;
    stack<int> s;
    for (int i = n - 1; i >= 0;i--)
    {
        if(s.empty())
        {
            res.push_back(-1);
            s.push(arr[i]);
        }
        else if(s.top()>arr[i])
        {
            res.push_back(s.top());
            s.push(arr[i]);
        }
        else 
        {
            while(!s.empty() && s.top()<=arr[i])
                s.pop();
            if(s.empty())
            {
                res.push_back(-1);
                s.push(arr[i]);
            }
            else if(s.top()>arr[i])
            {
                res.push_back(s.top());
                s.push(arr[i]);
            }
        }
    }
    reverse(res.begin(), res.end());
    return res;
}
int trw(int *arr,int n)
{
    vector<int> gl = ngl(arr, n);
    vector<int> gr = ngr(arr, n);
    vector<int> wob;
    int tw;
    for (int i = 0; i < n; i++)
    {
        if(gl[i]==-1 || gr[i]==-1)
            wob.push_back(0);
        else if(gl[i]!=-1 && gr[i]!=-1)
        {
            int wtr = min(gl[i], gr[i]) - arr[i];
            // wob.push_back(wtr);
            // tw += wtr;
            if(i-1>=0 && wob[i-1]!=0 && wtr+arr[i]!=wob[i-1]+arr[i-1])
            {
                wob.push_back(wob[i - 1] + arr[i - 1] - arr[i]);
                tw += wob[i - 1] + arr[i - 1] - arr[i];
            }
            else
            {
                wob.push_back(wtr);
                tw += wtr;
            }
        }
    }
    return tw;
}
int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int res = trw(arr, n);
    cout << res << endl;
}