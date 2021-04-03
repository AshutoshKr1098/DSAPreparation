/**
 * Problem: Sort a K sorted/nearly sorted array. 
 * Brute force: Insertion sort, by going back only K times for each element. Hence O(nk)
 * Better :     Use of min heap, because at any time a wrong element wont go outside it's window k. 
 *              Hende we need not care beyond K, and sort just the K parts to make it reach its correct place.
*/
#include<bits/stdc++.h>
using namespace std;
void kSorted(int *arr,int n,int k)
{
    priority_queue<int,vector<int>,greater<int>> pq;
    //j points to start of array, we go on increementing j as we sort array from left most part.
    //Thus at any time, the left part of j will always be sorted.
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
        if(pq.size()>k)
        {
            arr[j] = pq.top();
            pq.pop();
            j++;
        }
    }
    while(!pq.empty())
    {
        arr[j] = pq.top();
        pq.pop();
        j++;
    }
    return;
}
int main()
{
    int n, k;
    cin >> n >> k;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin>>arr[i];

    kSorted(arr, n,k);
    return 0;
}