#include<bits/stdc++.h>
using namespace std;

int countMergeInversions(int *arr,int l,int mid,int r)
{
    int nl = mid - l + 1;
    int nr = r - mid;

    int *left = new int[nl];
    int *right = new int[nr];

    for(int i = 0; i < nl; i++)
        left[i] = arr[i + l];
    for (int j = 0; j < nr;j++)
        right[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = l, cnt = 0;
    while(i<nl && j<nr)
    {
        if(left[i]<=right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            cnt += mid - (l+i) + 1;
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while(i<nl)
    {
        arr[k] = left[i];
        i++;
        k++;
    }
    while(j<nr)
    {
        arr[k]=right[j];
        j++;
        k++;
    }
    return cnt;
}
int countInversions(int *arr,int s,int e)
{
    if(s<e)
    {
        int mid = s+ (e - s) / 2;
        int lcount = countInversions(arr, s, mid);
        int rcount = countInversions(arr, mid + 1, e);
        int crossInversions = countMergeInversions(arr, s, mid, e);
        return lcount + rcount + crossInversions;
    }
    else
        return 0;
}

int main()
{
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int count=countInversions(arr,0,n-1);
    cout << count << endl;
}