/**
 * Lower Bound : lb(x)=el >=x [greater than or equal to x]
 * Upper Bound : ub(x)= el>x [strictly greater than x]
 * 
 * If the last element[N-1] of array is still smaller than x, then we return N as an imaginary index.
*/

#include<bits/stdc++.h>
using namespace std;

int lowerBound(int *arr,int n,int x)
{
    int s = 0, e = n - 1;
    int res = n;
    while (s <= e)
    {
        int mid = s+ (e - s) / 2;
        if(arr[mid]>=x)
        {
            res = mid;
            e= mid - 1;
        }
        else
            s = mid + 1;
    }
    return res;
}

int upperBound(int *arr,int n,int x)
{
    int s = 0, e = n - 1;
    int res = n;
    while (s <= e)
    {
        int mid = s+ (e - s) / 2;
        if(arr[mid]<=x)
        {
            s= mid + 1;
        }
        else
        {
            res = mid;
            e = mid - 1;
        }
    }
    return res;
}

int countElements(int *arr,int n,int x)
{
    int lb = lowerBound(arr, n, x);
    int ub = upperBound(arr,n,x);

    return ub - lb;
}

int main()
{
    int n;
    cin>>n;

    int *arr=new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    int x;
    cin>>x;

    int first=lowerBound(arr,n,x);
    int last=upperBound(arr,n,x);
    cout<<first<< " " <<last <<endl;
    int totalCount = countElements(arr,n,x);
    cout << totalCount << endl;
}