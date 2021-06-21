#include<bits/stdc++.h>
using namespace std;

void insertAppropriate(stack<int>&st,int x)
{
    if(st.size()==0 || st.top()>=x)
    {
        st.push(x);
        return;
    }
    int top = st.top();
    st.pop();
    insertAppropriate(st, x);
    st.push(top);
    return;
}
void insertAppropriateDesc(stack<int>&st,int x)
{
    if(st.size()==0 || st.top()<=x)
    {
        st.push(x);
        return;
    }
    int top = st.top();
    st.pop();
    insertAppropriateDesc(st, x);
    st.push(top);
    return;
}
void sortStackAscending(stack<int>&st)
{
    //Base case: Single element is always sorted
    if(st.size()==1)
        return;
    int x = st.top();
    st.pop();

    //Hypothesis: That this function will go and sort the remaining stack
    sortStackAscending(st);

    //Finally Induction step, that is we know that stack is now sorted, so we need to insert x at appropriate position
    insertAppropriate(st, x);
    return;
}
void sortStackDescending(stack<int>&st)
{
    if(st.size()==1)
        return;
    int  x = st.top();
    st.pop();
    sortStackDescending(st);
    insertAppropriateDesc(st, x);
    return;
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
    cout << "Before Sorting" << endl;
    printStack(st);    
    sortStackAscending(st);
    cout<<"After Sorting"<<endl;
    printStack(st);
    sortStackDescending(st);
    cout<<"After Sorting Descending"<<endl;
    printStack(st);
    return 0;
}