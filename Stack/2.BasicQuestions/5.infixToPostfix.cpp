#include<bits/stdc++.h>
using namespace std;

string itp(string s)
{
    stack<char> st;
    map<char, int> prec;
    prec['^'] = 3;
    prec['*'] = 2;
    prec['/'] = 2;
    prec['+'] = 1;
    prec['-'] = 1;
    string postfix = "";
    for(int i = 0; i < s.length(); i++)
    {
        if('0'<= s[i] && s[i] <= '9')
        {
            while(i<=s.length() && '0'<= s[i] && s[i] <= '9' )
            {
                postfix += s[i];
                i++;
            }
            postfix += ' ';
        }
        else if(st.empty() && s[i]=='(' || s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/')
            st.push(s[i]);
        else if(s[i]==')')
        {
            while(!st.empty() && st.top()!='(')
            {
                postfix += st.top();
                st.pop();
            }
            st.pop();
        }
        else if(st.top()!= '(' && prec[s[i]]<=prec[st.top()])
        {
            while(!st.empty() && st.top()!='(' && prec[st.top()] <= prec[s[i]])
            {
                postfix+= st.top();
                st.pop();;
            }
            st.push(s[i]);
        }
        else
            st.push(s[i]);
    }
    while(!st.empty())
    {
        postfix += st.top();
        st.pop();
    }
    return postfix;
}
int evalPostfix(string s)
{
    stack<int> st;
    for (int i = 0;i<s.length();i++)
    {
        if('0'<= s[i] && s[i]<='9')
            st.push(s[i] - '0');
        else
        {
            int op1 = st.top();
            st.pop();
            int op2 = st.top();
            st.pop();
            switch(s[i])
            {
                case '+':
                    st.push(op1 + op2);
                    break;
                case '-':
                    st.push(op1 - op2);
                    break;
                case '*':
                    st.push(op1 * op2);
                    break;
                case '/':
                    st.push(op1 / op2);
                    break;
                default:
                    break;
            }
        }
    }
    return st.top();
}
int main()
{
    string s;
    cin>>s;
    cout << itp(s) << endl;
}