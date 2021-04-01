/**
 * Problem: maxumum subarray length with sum K [having only positive integers]
 * Note: This problem don't contain any negative number, thus we can very easily use sliding window
 * but if there were negative number, sliding window won't work. 
 * We have to then use Hash table[to do later] Leetcode # 560
 * 
 * In a variable length sliding window concept, we have to consider all cases, less than equal to and greater than
 * That's why we have 3 conditions.
*/

#include<bits/stdc++.h>
using namespace std;
int largestArrayWithSumK(int *arr,int n,int k)
{
    int i = 0, j = 0, sum = 0;
    int maxi = INT_MIN;
    while (i <= j && j < n)
    {
        sum += arr[j];
        if(sum<k)
            j++;
        else if(sum==k)
        {
            maxi = max(maxi, (j - i + 1));
            j++;
            //I did not increase i because anyhow this case will be tackled in else block, where as soon as
            //on increasing j, sum>k and so else block will increase i.
        }
        else
        {
            while(i<=j && sum>k)
            {
                sum -= arr[i];
                i++;
            }
            if(sum==k)
                maxi = max(j - i + 1, maxi);
            j++;
        }
    }
    return maxi;
}
int main()
{
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int k;cin>>k;
    cout << largestArrayWithSumK(arr, n, k) << endl;
    return 0;
}