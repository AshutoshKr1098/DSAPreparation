/**
 * Problem: Leetcode# 1046 [Easy]
*/
#include<bits/stdc++.h>
using namespace std;
int lastStoneWeight(vector<int>& stones) {
    if(stones.size()==1)
        return stones[0];
    priority_queue<int>pq;
    for(auto it:stones)
        pq.push(it);
    while(!pq.empty())
    {
        int a= pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        if(a>b)
            pq.push(a-b);
        if(pq.size()==1)
            return pq.top();
        if(pq.size()==0)
            return 0;
    }
    if(pq.empty())
        return 0;
    else
        return pq.top();
    
}
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++)
        cin >> nums[i];
    cout << lastStoneWeight(nums) << endl;
}