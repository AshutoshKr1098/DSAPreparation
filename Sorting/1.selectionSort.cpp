#include<bits/stdc++.h>
using namespace std;

void selectionSort(int *arr,int n)
{
    //Last element will already be sorted, so we just need n-2 passes.
    // At any point of time, this will be the condition -> sorted i unsorted
    for (int i = 0; i < n - 1;i++)
    {
        int mindex = i;
        for (int j = i + 1; j < n; j++)
        {
            if(arr[j]<arr[mindex])
            {
                mindex = j;
            }
        }
        //To prevent unnecessary swap
        if(i!=mindex)
            swap(arr[i],arr[mindex]);
    }
    return;
}
void display(int *arr,int n)
{
    for (int i = 0; i < n;i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n;i++)
        cin >> arr[i];
    
    //1. Selection Sort
    selectionSort(arr, n);
    display(arr,n);
}