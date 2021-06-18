/**
 * Problem: Peak in a bitonic array (first increasing then decreasing)
*/
#include<bits/stdc++.h>
using namespace std;

int findPeak(int *arr,int n)
{
    int s=0, e = n - 1;
    while(s <=e)
    {
        int mid = s + (e - s) / 2;
        if(mid>0 && mid<n-1)
        {
            if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
                return mid;
            else if(arr[mid+1]>arr[mid])
                s = mid + 1;
            else
                e = mid - 1;
        }
        else if(mid==0)
            s = mid + 1;
        else if(mid==n-1)
            e = mid - 1;
    }
    return 0;
}
int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int peak = findPeak(arr, n);
    cout << arr[peak] << endl;
}
