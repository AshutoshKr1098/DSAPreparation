/**
 * Problem: Search a number in a nearly sorted array, which means a number that is supposed to be at index
 *          i can be at i,i-1,i+1.
*/
#include<bits/stdc++.h>
using namespace std;

int searchInNearlySortedArray(int *arr,int num,int n)
{
    int s = 0, e = n - 1;
    while(s<=e)
    {
        int mid = s + (e - s) / 2;
        if(arr[mid]==num) 
            return mid;
        else if(mid-1>=0 && arr[mid-1]==num)
            return mid - 1;
        else if(mid+1<=n-1 &&arr[mid+1]==num)
            return mid + 1;
        
        if(arr[mid]>num)
            e = mid - 2;
        else
            s = mid + 2;
    }
    return -1;
}
int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];
    int num;
    cin >> num;
    if(searchInNearlySortedArray(arr,num,n)!=-1)
        cout << "Element found at position " << searchInNearlySortedArray(arr, num, n) << endl;
    else
        cout << "Element not found" << endl;
    return 0;
}
