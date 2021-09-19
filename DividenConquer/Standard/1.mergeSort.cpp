#include<bits/stdc++.h>
using namespace std;
void merge(int *arr,int l,int mid,int r)
{
    //Step-1 Find the length of left segment and right segment
    int nl=mid-l+1;
    int nr=r-mid;


    //Step-2 Create 2 arrays, for both the segment, we can't merge and compare in just single arr array, 
    //hence we are storing them temporarily in 2 different arrays.
    int *left=new int[nl];
    int *right = new int[nr];

    //Copy the part from l to mid in left array 
    for(int i=0;i<nl;i++)
    {
        left[i]=arr[l+i];
    }

    //Copy the part from mid+1 to r in right array
    for(int i=0;i<nr;i++)
        right[i]=arr[mid+1+i];
    
    //Now we have both the copies, so just start the merge process

    //i and j will be at start of newly created arrays, and k will point to l.
    int i=0,j=0,k=l;
    while(i<nl && j<nr)
    {
        if(left[i]<right[j])
        {
            arr[k]=left[i];
            i++;
        }
        else
        {
            arr[k]=right[j];
            j++;
        }
        k++;
    }

    //The remaining 2 while loops are for leftover elements in either of the segment.
    while(i<nl)
    {
        arr[k]=left[i];
        i++;
        k++;
    }
    while(j<nr)
    {
        arr[k]=right[j];
        j++;
        k++;
    }
    return;
}
void mergeSort(int *arr,int s,int e)
{
    //We will choose s<e and ignore s>e or s==e, because s==e means 1 element is there which is already sorted, and s>e makes no sense.
    if(s<e)
    {
        int mid=s+(e-s)/2;
        mergeSort(arr,s,mid);
        mergeSort(arr,mid+1,e);
        merge(arr,s,mid,e);
    }
    return;
}
void displayArray(int *arr,int n)
{
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
int main()
{
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    mergeSort(arr,0,n-1);
    displayArray(arr,n);
}