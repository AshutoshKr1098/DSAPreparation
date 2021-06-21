/**
 * Problem: Search the number in a sorted rotated array
*/
#include<bits/stdc++.h>
using namespace std;

int binary_search(int *arr,int num,int s,int e)
{
    while(s<=e)
    {
        int mid = s + (e - s) / 2;
        if(arr[mid]==num)
            return mid;
        else if(arr[mid]<num)
            s = mid + 1;
        else
            e = mid - 1;
    }
    return -1;
}
int findInSortedRotated(int *arr,int num,int n)
{
    int middle = findMinPos(arr, n);
    if(arr[middle]==num)
        return middle;
    else if(middle<0 && middle<n-1)
    {
        if(num>=arr[0] && num<=arr[middle-1])
            return binary_search(arr, num, 0, middle - 1);
        else
            return binary_search(arr, num, middle + 1, n-1);
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