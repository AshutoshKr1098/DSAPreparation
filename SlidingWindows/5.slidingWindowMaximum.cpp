/**
 * Leetcode: Sliding Window Maximum [ HARD ]
 * Problem: For each subarray of size K, return the maximum in that subarray. 
*/

//This problem is very similar to first negative number problem, only difference is we need deque to keep 
//track of the largest element for that subarray.

#include<bits/stdc++.h>
using namespace std;
vector<int>slidingWindowMaximum(int *arr,int n,int k)
{
    int i = 0, j = 0;
    vector<int> res;
    deque<int> dq; //We will use deque, inplace of queue because we want to have pop front and pop back.
    while(j<n)
    {
        //Push from behind, until you find an element already in queue which is greater than incoming eleement.
        //At all moment, the front of queue will represent the maximum in that window. 
        if(dq.empty())
            dq.push_back(arr[j]);
        else
        {
            while(!dq.empty() && dq.back()<arr[j])
                dq.pop_back();
            dq.push_back(arr[j]); 
        }
        if(j-i+1<k)
            j++;
        else if(j-i+1==k)
        {
            res.push_back(dq.front());
            //Popping out the front element, if arr[i] is same as it, since that element is no more part of window.
            if(arr[i]==dq.front())
                dq.pop_front();
            i++;
            j++;
        }
    }
    return res;
}
int main()
{
    int n, k;
    cin >> n >> k;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> mxmInWindow = slidingWindowMaximum(arr, n, k);
    for(auto it:mxmInWindow)
        cout<<it<<" ";
    return 0;
}