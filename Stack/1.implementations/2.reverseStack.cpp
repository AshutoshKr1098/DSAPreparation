#include<bits/stdc++.h>
using namespace std;

void insertAtEnd(stack<int>&st,int x)
{
    //Base case
    if(st.size()==0)
    {
        st.push(x);
        return;
    }

    //Induction
    int top = st.top();
    st.pop();
    insertAtEnd(st, x);
    st.push(top);
    return;
}
void reverseStack(stack<int>&st)
{
    //Base case when stack size is 1.
    if(st.size() == 0)
        return;

    int x = st.top();
    st.pop();
    reverseStack(st);
    insertAtEnd(st, x);
    return;
}
void printStack(stack<int>st)
{
    while(!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    return;
}
int main()
{
    int n = 0;
    stack<int> st;
    while (n != -1)
    {
        cin >> n;
        st.push(n);
    }
    cout << "Before Reversal" << endl;
    printStack(st);    
    reverseStack(st);
    cout<<"After Reversal"<<endl;
    printStack(st);
    return 0;
}