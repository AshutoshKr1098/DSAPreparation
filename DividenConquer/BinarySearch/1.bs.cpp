#include<bits/stdc++.h>
using namespace std;
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