/**
 * Problem: Find the number of times a sorted array has been rotated
*/

#include<bits/stdc++.h>
using namespace std;

int count_number_of_rotations(int *arr,int s,int e,int n)
{
    if(s>e)
        return -1;    
    int mid = s + (e - s) / 2;
    if(0<mid && mid<n-1 && arr[mid-1]>arr[mid] && arr[mid]<arr[mid+1])
        return mid;  
    if(mid==0 && arr[mid]<arr[n-1]) //A case when no rotation is made, thus 0th element is anyway gonna be less than end element
        return 0;
    else if(mid==n-1 && arr[mid]<arr[mid-1]) //A case where least element is at last, then anyway it's gonna be less than it's previous one
        return n-1;
    else if(arr[mid]>arr[n-1])
        return count_number_of_rotations(arr, mid + 1, e, n);
    else
        return count_number_of_rotations(arr, s, mid - 1, n);
}
int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int count_rotations = count_number_of_rotations(arr, 0, n - 1, n);
    cout << count_rotations << endl;
}