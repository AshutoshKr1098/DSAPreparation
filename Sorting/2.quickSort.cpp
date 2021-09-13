#include<bits/stdc++.h>
using namespace std;

void display(int *arr,int n)
{
    for (int i = 0; i < n;i++)
        cout << arr[i] << " ";
    cout << endl;
}

int partition(int *arr,int s,int e)
{
    int pivot = arr[e];
    int i = s - 1;
    for (int j = s; j < e; j++)
    {
        if(arr[j]<=pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    //In the end bring this to correct place.
    swap(arr[i + 1], arr[e]);
    return i+1;
}

void quickSort(int *arr,int s,int e)
{
    if(s<e)
    {
        int pi=partition(arr,s,e);
        quickSort(arr,s,pi-1);
        quickSort(arr, pi + 1, e);
    }
    return;
}
int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n;i++)
        cin >> arr[i];
    
    //1. Selection Sort
    quickSort(arr, 0,n-1);
    display(arr,n);
}