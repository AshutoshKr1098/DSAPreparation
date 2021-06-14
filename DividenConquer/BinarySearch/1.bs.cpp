#include<bits/stdc++.h>
using namespace std;

//Recursive Implementation
bool binary_search_num(int *arr,int num,int s,int e)
{
    if(s>e)
        return false;
    int mid = s + (e - s) / 2;
    if(arr[mid]==num)
        return true;
    else if(arr[mid]<num)
        return binary_search_num(arr, num, mid + 1, e);
    else
        return binary_search_num(arr, num, s, mid - 1);
}

//Iterative Implementation

bool binary_search_num(int *arr,int num,int n)
{
    int s = 0, e = n - 1;
    while(s<=e)
    {
        int mid = s + (e - s) / 2;
        if(arr[mid]==num)
            return true;
        else if(arr[mid]<num)
            s = mid + 1;
        else
            e = mid - 1;
    }
    return false;
}

//Agnostic Binary Search (where order of sorting is unknown to us)
bool agnostic_binary_search(int *arr,int num,int n)
{
    int s = 0, e = n - 1;
    if(s==e && arr[s]==num)
        return true;
    else if(s==e && arr[s]!=num)
        return false;
        
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if(arr[mid]==num)
            return true;
        else if(arr[mid]<num)
        {
            if(arr[0]<arr[n-1])
                s = mid + 1;
            else
                e = mid - 1;
        }
        else
        {
            if(arr[0]<arr[n-1])
                e = mid - 1;
            else
                s = mid + 1;
        }
    }
    return false;
}

int main()
{
    int n;
    cin >> n;int *arr=new int[n];
    for(int i=0;i<n; i++)
        cin >> arr[i];
    int k;
    cin >> k;
    if(binary_search_num(arr, k, 0, n - 1))
        cout << "Element found" << endl;
    else
        cout<<"Element not found"<< endl;
}