#include<bits/stdc++.h>
using namespace std;

//This method deletes the middle element and returns the middle element as well
int deleteMidAndReturn(stack<int>&st,int cnt,int n)
{
    //Handling empty stack
    if(st.empty())
        return -1;
    
    //If middle element is the stack's top element
    if(cnt==n/2)
    {
        int mid = st.top();
        st.pop();
        return mid;
    }

    //Pop the element and reach out for middle element
    int top = st.top();
    st.pop();
    cnt++;
    int res = deleteMidAndReturn(st, cnt, n);
    st.push(top);
    return res;
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
    stack<int> st;
    while (n != -1)
    {        
        st.push(n);
        cin >> n;
    }
    cout << "Before Deleting mid" << endl;
    printStack(st);    
    int mid = deleteMidAndReturn(st,0,st.size());
    cout<<"After Deleting mid: "<<mid<<endl;
    printStack(st);    
    return 0;
}