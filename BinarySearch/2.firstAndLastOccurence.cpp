#include<bits/stdc++.h>
using namespace std;

/***
 * Method :     findFirstOccurence 
 * Description: This is an iterative method to find First Occurence of x in sorted array
 * Parameters : arr - sorted array
 *              n   - total number of elements in array
 *              x   - element to find 
 * Return     : -1 if element is not found
 *               index of first occurence of element if it is found 
 * */

int findFirstOccurence(int *arr,int n,int x)
{
    //Step-1 Initialize 2 pointers on extreme end of array.
    int s=0,e=n-1;

    //This is the variable that will hold the index of first occurence of x.
    int firstOccurenceIndex = -1;

    //Step-2 Continue in loop until s becomes greater than e(which is the case when el is not found)
    while(s<=e)
    {
        //Step-3 Find the mid of the currently considered segment
        int mid=s+(e-s)/2;

        //Step-4 If mid ==x , then this is the element we had been looking for
        // So now look for more towards left, hence e=mid-1, while saving the index of mid into that vaRIABLE
        if(arr[mid]==x)
        {
            firstOccurenceIndex = mid;
            e = mid - 1;
        }

        //Else if mid!=x and rather arr[mid]<x which means, all elements to the left of mid is invalid
        //So in this case just update the value of s to look in right segment
        else if(arr[mid]<x)
            s=mid+1;

        //Similarly, the mid is greater than x.. so all elements to right of mid and including mid is 
        //invalid so search on left side, hence move e=mid-1.
        else
            e=mid-1;
    }

    //Return the variable that stores first occurence (-1 in case it's not found)
    return firstOccurenceIndex;
}

/***
 * Method :     findLastOccurence 
 * Description: This is an iterative method to find last Occurence of x in sorted array
 * Parameters : arr - sorted array
 *              n   - total number of elements in array
 *              x   - element to find 
 * Return     : -1 if element is not found
 *               index of last occurence of element if it is found 
 * */

int findLastOccurence(int *arr,int n,int x)
{
    //Step-1 Initialize 2 pointers on extreme end of array.
    int s=0,e=n-1;

    //This is the variable that will hold the index of first occurence of x.
    int lastOccurenceIndex = -1;

    //Step-2 Continue in loop until s becomes greater than e(which is the case when el is not found)
    while(s<=e)
    {
        //Step-3 Find the mid of the currently considered segment
        int mid=s+(e-s)/2;

        //Step-4 If mid ==x , then this is the element we had been looking for
        // So now look for more towards right, hence s=mid+1, while saving the index of mid into that vaRIABLE
        if(arr[mid]==x)
        {
            lastOccurenceIndex = mid;
            s = mid + 1;
        }

        //Else if mid!=x and rather arr[mid]<x which means, all elements to the left of mid is invalid
        //So in this case just update the value of s to look in right segment
        else if(arr[mid]<x)
            s=mid+1;

        //Similarly, the mid is greater than x.. so all elements to right of mid and including mid is 
        //invalid so search on left side, hence move e=mid-1.
        else
            e=mid-1;
    }

    // Return the variable (-1 if the element is not found).
    return lastOccurenceIndex;
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

    int first=findFirstOccurence(arr,n,x);
    int last=findLastOccurence(arr,n,x);
    if(first!=-1)
        cout<<x<<" found at position "<<first<<endl;
    else
        cout<<x<<" not present in array"<<endl;
}