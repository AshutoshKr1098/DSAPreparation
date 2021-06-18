/**
 * Problem: Find median of two sorted arrays of same size
*/

#include<bits/stdc++.h>
using namespace std;

double findMedian(vector<int>a,vector<int>b,int sa,int ea,int sb,int eb)
{
    if(ea-sa==1 && eb-sb==1)
        return (max(a[sa],a[ea])+min(b[sb],b[eb]))/2;
    
    //Now size of final arrays are greater than two so find the medians
    int m1 = sa + (ea-sa)/2;
    int m2 = sb + (eb-sb)/2;

    if(a[m1]==b[m2])
        return a[m1];
    
    if(a[m1]<b[m2])
        return findMedian(a, b, m1, ea, sb, m2);
    if(a[m1]>b[m2])
        return findMedian(a, b, sa, m1, m2, eb);
}
int main()
{
    int n;
    cin >> n;
    vector<int> v1(n), v2(n);
    for(int i= 0; i < n; i++)
        cin>>v1[i];
    for(int i= 0; i < n; i++)
        cin>>v2[i];
    
    int median = findMedian(v1, v2);
    cout<<median<<endl;
    return 0;
}