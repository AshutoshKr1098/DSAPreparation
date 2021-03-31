/**
 * Problem: We are given an array which consists of positive and negative numbers. We have to find the first
 *          negative number in each window of size K. If in that window, we dont have any negative number then
 *          return 0 for that case.
*/
#include<bits/stdc++.h>
using namespace std;
vector<int>firstNegativeInWindowK(int *arr,int n,int k)
{
    int i = 0, j = 0;
    vector<int> res;
    queue<int> q; //We will maintain a queue of all negative numbers encountered in the span of that window.
    while(j<n)
    {
        if(arr[j]<0) //Push the negative number inside our queue
            q.push(arr[j]);
        if(j-i+1<k) //If window size is not hit, then we first try to hit our window size.
            j++;
        else //Once we hit our window, we try to execute the logic that will give us desired result
        {
            //As soon we hit window, we need to push the first negative number in vector. If q is empty that
            //means, no negative number exist for that window. We put 0 to mark absence of negative number. 
            //Else we push the front of queue, because that is the first negative number in that window.
            if(q.empty()) 
                res.push_back(0);
            else
                res.push_back(q.front());

            //Now we will slide the window forward. If the element going out of window was the first negative number
            //in the window, then we also need to pop it from queue. Because queue'e elements denote all negative 
            //numbers within that window size. But q.front() is no more part of the window, so we pop it.
            if(arr[i]==q.front())
                q.pop();
            //Then we slide our window.
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

    vector<int> firstNegative = firstNegativeInWindowK(arr, n, k);
    for(auto it:firstNegative)
        cout<<it<<" ";
    return 0;
}