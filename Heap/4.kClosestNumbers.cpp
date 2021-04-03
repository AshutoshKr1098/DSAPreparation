/**
 * Problem: Sort a K sorted/nearly sorted array. 
 * Brute force: Insertion sort, by going back only K times for each element. Hence O(nk)
 * Better :     Use of min heap, because at any time a wrong element wont go outside it's window k. 
 *              Hende we need not care beyond K, and sort just the K parts to make it reach its correct place.
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> kClosestNumbers(int *arr,int n,int k,int x)
{
    priority_queue<pair<int,int>> pq; //storing the [difference,arr[i]] and heap will be made based on the difference.
    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        pq.push(make_pair(abs(x-arr[i]),arr[i]));
        if(pq.size()>k)
        {            
            pq.pop();           
        }
    }
    while(!pq.empty())
    {
        res.push_back(pq.top().second);
        pq.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}
int main()
{
    int n, k, x;
    cin >> n >> k >> x;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin>>arr[i];

    vector<int>res = kClosestNumbers(arr, n,k,x);
    for(auto it:res)
        cout << it << " ";
    return 0;
}