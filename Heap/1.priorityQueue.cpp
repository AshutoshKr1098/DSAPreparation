/**
 * To implement heap, we make use of PriorityQueue in STL. A heap data structure can be of 2 types: Min and Max 
 * priority_queue<int> pq => max heap
 * priority_queue<int,vector<int>,greater<int>> pq => min heap
 * 
 * Functions available to us: 1. push 2. pop 3. top 4. empty 5. size
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<int,vector<int>,greater<int>> pq; //min heap
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    
    //insertion in heap
    for(int i = 0; i < n; i++)
        pq.push(arr[i]);
    
    //removal from heap and printing the top value.
    while(!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    return 0;
}