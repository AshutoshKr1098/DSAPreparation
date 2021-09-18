#include<bits/stdc++.h>
using namespace std;

/***
 * Method : binarySearchIterative
 * Description: This is an iterative method to search an element 
 *              in the array which should be sorted
 * Parameters : arr - sorted array
 *              n   - total number of elements in array
 *              x   - element to find 
 * Return     : -1 if element is not found
 *               index of element if it is found 
 * */

int binarySearchIterative(int *arr,int n,int x)
{
    //Step-1 Initialize 2 pointers on extreme end of array.
    int s=0,e=n-1;

    //Step-2 Continue in loop until s becomes greater than e(which is the case when el is not found)
    while(s<=e)
    {
        //Step-3 Find the mid of the currently considered segment
        int mid=s+(e-s)/2;

        //Step-4 If mid ==x , then this is the element we had been looking for, hence return the index
        if(arr[mid]==x)
            return mid;
        
        //Else if mid!=x and rather arr[mid]<x which means, all elements to the left of mid is invalid
        //So in this case just update the value of s to look in right segment
        else if(arr[mid]<x)
            s=mid+1;

        //Similarly, the mid is greater than x.. so all elements to right of mid and including mid is 
        //invalid so search on left side, hence move e=mid-1.
        else
            e=mid-1;
    }

    //You reach this step when element is not found in array, hence it's safe to return -1.
    return -1;
}


/******* Code for Recursive Approach *************/

/***
 * Method : binarySearchHelperRecursive
 * Description: This is a helper method which is being called by binarySearchRecursive.
 * Parameters : arr - array
 *              s   - start index of segment to look for
 *              e   - end index of segment to look for
 *              x   - element to find 
 * Return     : -1 if element is not found
 *               index of element if it is found 
 * */

int binarySearchHelperRecursive(int *arr,int s,int e, int x)
{
    if(s<=e)
    {
        int mid=s + (e - s) / 2;
        if(arr[mid]==x)
            return mid;
        else if(arr[mid]<x)
            return binarySearchHelperRecursive(arr, mid + 1, e, x);
        else
            return binarySearchHelperRecursive(arr, s, mid - 1, x);
    }
    return -1;
}

/***
 * Method : binarySearchRecursive
 * Description: This is a wrapper method which calls binarySearchHelperRecursive to search an element 
 *              recursively in the array which should be sorted
 * Parameters : arr - sorted array
 *              n   - total number of elements in array
 *              x   - element to find 
 * Return     : -1 if element is not found
 *               index of element if it is found 
 * */
int binarySearchRecursive(int *arr,int n,int x)
{
    return binarySearchHelperRecursive(arr, 0, n - 1, x);
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

    int pos=binarySearchIterative(arr,n,x);
    if(pos!=-1)
        cout<<x<<" found at position "<<pos<<endl;
    else
        cout<<x<<" not present in array"<<endl;
}