#include<bits/stdc++.h>
using namespace std;
void combinationSum(int *arr,int n,int sum,int total,int pos,vector<vector<int>>&res,vector<int>temp)
{
    if(pos>=n || sum>total)
        return;
    if(sum==total)
    {
        vector<int> temp2 = temp;
        temp.pop_back();
        sort(temp2.begin(), temp2.end());
        // st.insert(temp);
        res.push_back(temp2);        
        return;
    }
    for (int i = pos; i < n;i++)
    {
        temp.push_back(arr[i]);
        sum+=arr[i];        
        combinationSum(arr, n, sum, total, i, res, temp);
        temp.pop_back();
        sum-=arr[i];
        // combinationSum(arr, n, sum, total, pos+1, res, temp);
        // temp.pop_back();
        // sum -= arr[i];
    }
    return;
}
int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    int sum;
    cin >> sum;
    vector<vector<int>>res;
    vector<int> temp;
    set<vector<int>> st;
    combinationSum(arr, n, 0, sum, 0, res, temp);
    // for(auto it:st)
    //     res.push_back(it);
    for (auto it : res)
    {
        for(auto x:it)
            cout << x << " ";
        cout << endl;
    }
}