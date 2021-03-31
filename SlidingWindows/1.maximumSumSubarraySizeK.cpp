/**
 * Problem Statement: We need to find maximum sum for all window of size K.
 * This is a classical sliding windows problem, where we slide initially till we hit a window of size K.
 * Once we hit a window of size K, we make sure to maintain it and perform our operation
*/

#include<bits/stdc++.h>
using namespace std;
int mssk(int *arr,int n,int k)
{
    //Initializing the pointers to mark the start and end of our window
    int i = 0, j = 0;
    int sum = 0;
    int maxSum = INT_MIN;
    //Entering the while loop with the condition till when we need to slide our window.
    while(j<n) // Last of window moves out of array and we exit. We can also write i<n-k+1
    {
        sum += arr[j];
        if(j-i+1<k) //Checking if we hit our window, if not first just reach till window size.
            j++;
        else //Now once we reach our window, we perform the task.
        {
            maxSum = max(maxSum, sum);
            sum-=arr[i]; //Sliding the window forward, by increasing i and taking off it's share from sum.
            i++;
            j++;
        }
    }
    return maxSum;
}
int main()
{
    int n, k;
    cin >> n >> k;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int maximumSum = mssk(arr, n, k);
    cout << maximumSum << endl;
}