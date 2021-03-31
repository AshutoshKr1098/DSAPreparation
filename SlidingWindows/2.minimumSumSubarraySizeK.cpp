/**
 * Problem Statement: We need to find minimum sum for all window of size K.
 * This is a variation of the classical sliding windows problem(maximum sum subarray), 
 * where we slide initially till we hit a window of size K.
 * Once we hit a window of size K, we make sure to maintain it and perform our operation
*/

#include<bits/stdc++.h>
using namespace std;
int mssk(int *arr,int n,int k)
{
    //Initializing the pointers to mark the start and end of our window
    int i = 0, j = 0;
    int sum = 0;
    int minSum = INT_MAX;
    //Entering the while loop with the condition till when we need to slide our window.
    while(j<n) // Last of window moves out of array and we exit. We can also write i<n-k+1
    {
        sum += arr[j];
        if(j-i+1<k) //Checking if we hit our window, if not first just reach till window size.
            j++;
        else //Now once we reach our window, we perform the task.
        {
            minSum = min(minSum, sum);
            sum-=arr[i]; //Sliding the window forward, by increasing i and taking off it's share from sum.
            i++;
            j++;
        }
    }
    return minSum;
}
int main()
{
    int n, k;
    cin >> n >> k;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int minimumSum = mssk(arr, n, k);
    cout << minimumSum << endl;
}