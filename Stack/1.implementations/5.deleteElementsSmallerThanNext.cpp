/*
Problem: We need to delete K elements that are smaller ( or are getting smaller ) than their next element
Example: 20 10 25 30 40, K=2
        25 30 40  is the output

        First: 20 25 30 40 [since 10 was smaller than 25, so deleted 10] K=1
        Then : 25 30 40    [After deleting 10, 20 is next neighbour of 25, thus deleted 20] K=0
*/

#include<bits/stdc++.h>
using namespace std;
void deleteKSmaller(stack<int>&st,int &k)
{
    if(st.size()==1)
        return;
    int top = st.top();
    st.pop();
    deleteKSmaller(st, k);
    if(top < st.top() && k>0)
        k--;
    else
        st.push(top);
    return;
}
void deleteSmaller(int *arr,int n,int k)
{
    stack<int>st;    
    int i =0;
    while(i<n)
    {
        if(st.empty())
        {            
            st.push(arr[i]);
        }
        else
        {
            if(k>0 && st.top()<arr[i])
            {
                while(k>0 && !st.empty() && st.top()<arr[i])
                {                    
                    st.pop();
                    k--;
                }                
            }           
            st.push(arr[i]);            
        }
        i++;
    }
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}
void printStack(stack<int>st)
{
    while(!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout<<endl;
    return;
}
int main()
{
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];
    int k;
    cin >> k;

    //If the question wants us to delete from beginning
    deleteSmaller(arr,n,k);

    //if question wants us to delete from end
    // stack<int> st;
    // while (n != -1)
    // {        
    //     st.push(n);
    //     cin >> n;
    // }
    
    // cout << "Before Deleting" << endl;
    // printStack(st);
    // deleteKSmaller(st, k);
    // cout << "After Deleting K Smaller Elements" << endl;
    // printStack(st);
    return 0;
}
