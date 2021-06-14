/**
 * Problem: Find first and last occurence of a number in given sorted array
 *          If the number does not exist then return -1
*/

#include<bits/stdc++.h>
using namespace std;

bool binary_search_num(int *arr,int num,int n)
{
    int s = 0, e = n - 1;
    while(s<=e)
    {
        int mid = s + (e - s) / 2;
        if(arr[mid]==num)
            return true;
        else if(arr[mid]<num)
            s= mid + 1;
        else
            e = mid - 1;
    }
    return false;
}

int firstOccurence(int *arr,int num,int n)
{
    int s = 0, e = n - 1;
    int res = -1;
    while(s<=e)
    {
        int mid = s + (e - s) / 2;
        if(arr[mid]==num)
        {
            res = mid;
            e = mid - 1;
        }
        else if(arr[mid]<num)
        {
            s= mid + 1;
        }
        else
            e = mid - 1;
    }
    return res;
}

int lastOccurence(int *arr,int num,int n)
{
    int s = 0, e = n - 1;
    int res = -1;
    while(s<=e)
    {
        int mid = s + (e - s) / 2;
        if(arr[mid]==num)
        {
            res = mid;
            s= mid + 1;
        }
        else if(arr[mid]<num)
            s = mid + 1;
        else
            e = mid - 1;
    }
    return res;
}

int countOccurence(int *arr,int num,int n)
{
    if(binary_search_num(arr,num,n))
    {
        return lastOccurence(arr, num, n) - firstOccurence(arr, num, n) + 1;
    }
    else
        return 0;
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
    cout << "first occurence of number" << num << " is " << firstOccurence(arr, num, n) << endl;
    cout << "last occurence of number" << num << " is " << lastOccurence(arr, num, n) << endl;
    cout << "total occurence of number" << num << " is " << countOccurence(arr, num, n) << endl;
 

}