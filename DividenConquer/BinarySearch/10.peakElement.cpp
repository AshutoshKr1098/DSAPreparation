/**
 * Problem: Find Peak element in a array(Need not be sorted)
 * Approach: This is a classical question, which uses Binary search on an unsorted array. 
 *           We make our decision based on local neighbours and it is bound to give us one of the peak */

#include<bits/stdc++.h>
using namespace std;

int findPeakElement(int *arr,int n)
{
    //When size is 1, then we consider that element to be peak element
    if(n==1)
        return 0;
    int s = 0, e = n - 1;
    while(s<=e)
    {
        int mid = s + (e - s) / 2;
        if(mid>0 && mid<n-1)
        {
            if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
                return mid;
            else if(arr[mid]<arr[mid-1])
                e = mid - 1;
            else
                s = mid + 1;
        }
        else if(mid==0)
        {
            if(arr[mid]>arr[mid+1])
                return 0;
            else
                s = mid + 1;
        }
        else if(mid==n-1)
        {
            if(arr[mid]>arr[mid-1])
                return n - 1;
            else
                e = mid - 1;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++)
        cin>>arr[i];

    int peak = findPeakElement(arr, n);
    cout << arr[peak] << endl;
}
