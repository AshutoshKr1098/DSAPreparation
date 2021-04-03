#include<bits/stdc++.h>
using namespace std;
vector<int> kFrequentNumbers(int *arr,int n,int k)
{
    map<int, int> mp;
    for(int i=0;i<n;i++)
        mp[arr[i]]++;
    priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>>pq;
    for(auto it:mp)
    {
        pq.push(make_pair(it.second,it.first));
        if(pq.size()>k)
            pq.pop();
    }
    vector<int> res;
    while(!pq.empty())
    {
        res.push_back(pq.top().second);
        pq.pop();
    }
    return res;
}
int main()
{
    int n,k;
    cin >> n >> k;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin>>arr[i];
    vector<int> kfreq = kFrequentNumbers(arr, n, k);
    for(auto it:kfreq)
        cout << it << " ";
    cout << endl;
    return 0;
}