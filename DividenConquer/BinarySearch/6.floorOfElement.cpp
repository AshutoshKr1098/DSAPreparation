/**
 * Problem: Find floor of a number, where floor of a number present will be the number itself
*/
#include<bits/stdc++.h>
using namespace std;
int findFloor(int *arr,int num,int n)
{
    if(arr[0]>num)
        return -1;
    if(arr[n-1]<num)
        return arr[n - 1];
    int s = 0, e = n - 1;
    int floor = -1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if(arr[mid]==num)
            return arr[mid];
        if(arr[mid]<num)
        {
            s = mid + 1;
            res = min(num, arr[mid]);
        }
        if(arr[mid]>num)
            e = mid - 1;
    }
    return res;
}
int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int num;
    cin >> num;
    floor = findFloor(arr, num, n);
}