/**
 * Problem: Search the number in a sorted rotated array
*/
#include<bits/stdc++.h>
using namespace std;

int findInSortedRotated(int *arr,int num,int n)
{
    int s = 0, e = n - 1;
    while(s<=e)
    {
        int mid = s + (e - s) / 2;
        if(arr[mid]==num)
            return mid;
        else if(num>arr[e] && arr[mid]>arr[e])
        {
            if(arr[mid]>num)
                e = mid - 1;
            else
                s = mid + 1;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int num;
    cin >> num;
    int res = findInSortedRotated(arr, num, n);
}