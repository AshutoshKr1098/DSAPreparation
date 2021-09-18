/**
 * Lower Bound : lb(x)=el >=x [greater than or equal to x]
 * Upper Bound : ub(x)= el>x [strictly greater than x]
 * 
 * If the last element[N-1] of array is still smaller than x, then we return N as an imaginary index.
*/

#include<bits/stdc++.h>
using namespace std;

/***
 * Method :     lowerBound
 * Description: This is an iterative method to find lower bound of x in sorted array
 * Parameters : arr - sorted array
 *              n   - total number of elements in array
 *              x   - element to find 
 * Return     :  n if all elements are smaller than x
 *               index of lower bound element 
 * */
int lowerBound(int *arr,int n,int x)
{
    int s = 0, e = n - 1;
    int res = n;
    while (s <= e)
    {
        int mid = s+ (e - s) / 2;

        // if an element is equal to or greater, than we take it as a candidate and keep exploring it's left
        if(arr[mid]>=x)
        {
            res = mid;
            e= mid - 1;
        }

        // else we search for appropriate candidate on right
        else
            s = mid + 1;
    }
    return res;
}

/***
 * Method :     upperBound
 * Description: This is an iterative method to find upper bound of x in sorted array
 * Parameters : arr - sorted array
 *              n   - total number of elements in array
 *              x   - element to find 
 * Return     :  n if all elements are smaller than x
 *               index of upper bound element 
 * */
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

        //A suitable candidate for upper bound is element which is strictly greater than x
        else
        {
            res = mid;
            e = mid - 1;
        }
    }
    return res;
}

/***
 * Method :     countElements
 * Description: This is an iterative method to count total occurences of x in sorted array
 * Parameters : arr - sorted array
 *              n   - total number of elements in array
 *              x   - element to find 
 * Return     :  difference of upper bound and lower bound of x.
 * */
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