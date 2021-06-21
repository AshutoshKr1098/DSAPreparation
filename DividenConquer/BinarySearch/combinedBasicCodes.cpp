#include<bits/stdc++.h>
using namespace std;
//Recursive approach
int binary_search_normal(int *arr,int num,int s,int e)
{
    if(s>e)
        return -1;
    int mid = s + (e-s)/2;
    int res = -1;
    if(arr[mid]==num)
        res= mid;
    else if(arr[mid]>num)
        res = binary_search_normal(arr,num,s,mid-1);
    else
        res = binary_search_normal(arr,num,mid+1,e);
    
    return res;        
}

//Iterative Approach

int binary_search_normal_iterative(int *arr,int num,int n)
{
    int s=0,e=n-1;
    int res = -1;
    while(s<=e)
    {
        int mid = s+(e-s)/2;
        if(arr[mid]==num)
        {
            res = mid;
            break;
        }
        else if(arr[mid]<num)
            s=mid+1;
        else
            e=mid-1;
    }
    return res;
}

//3. Binary search on reverse sorted array ( aka descending array binary search) - Iterative Approach
int bs_reverse_sorted_array(int *arr,int num,int n)
{
    int s=0,e=n-1;
    while(s<=e)
    {
        int mid = s + (e-s)/2;
        if(arr[mid]==num)
            return mid;
        else if(arr[mid]>num)
            s=mid+1; // Unlike in normal search e=mid-1 here
        else
            e=mid-1; //Unlike in normal search, s = mid+1 here
    }    
    return -1;
}

//4. Binary search on a sorted array when order is not known
int bs_order_not_known(int *arr,int num,int n)
{
    //Just checking the case when either all elements are same or array has only 1 element
    if(arr[0]==arr[n-1])
    {
        if(arr[0]==num)
            return 0;
        else
            return -1;
    }

    //Check the nature of sorted array
    if(arr[0]<arr[n-1])
        return binary_search_normal_iterative(arr,num,n);
    else
        return bs_reverse_sorted_array(arr,num,n);
}

//5a. First Occurence of a number in sorted array
int firstOccurence(int *arr,int num,int n)
{
    int s=0,e=n-1;
    int res=-1;
    while(s<=e)
    {
        int mid = s+(e-s)/2;
        if(arr[mid]==num)
        {
            res=mid;
            e=mid-1;
        }
        else if(arr[mid]>num)
            e=mid-1;
        else
            s=mid+1;
    }
    return res;
}

//5b. Last Occurence of a number in sorted array
int lastOccurence(int *arr,int num,int n)
{
    int s=0,e=n-1;
    int res=-1;
    while(s<=e)
    {
        int mid = s+(e-s)/2;
        if(arr[mid]==num)
        {
            res=mid;
            s=mid+1;
        }
        else if(arr[mid]>num)
            e=mid-1;
        else
            s=mid+1;
    }
    return res;
}

//6. Count total occurence of a number
int countOccurences(int *arr,int num,int n)
{
    int fc = firstOccurence(arr,num,n);
    int lc = lastOccurence(arr,num,n);

    if(fc!=-1 && lc!=-1)
        return lc-fc+1;
    else
        return 0;
}
int main()
{
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i =0;i<n;i++)
        cin>>arr[i];
    int num;
    cin>>num;
    //1. Normal Binary Search 
    // cout<<binary_search_normal(arr,num,0,n-1)<<endl;
    // cout<<binary_search_normal_iterative(arr,num,n)<<endl;
    // cout<<bs_order_not_known(arr,num,n);

    //2. Descending Binary search

    //3. Order not known Binary search

    //4. First and Last Occurence
    cout<<firstOccurence(arr,num,n)<<endl;
    cout<<lastOccurence(arr,num,n)<<endl;
    cout<<countOccurences(arr,num,n)<<endl;
}