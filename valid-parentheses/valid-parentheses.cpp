class Solution {
public:
    bool isValid(string s) {
        if(s.size()==0)
            return true;
        stack<char>st;
        for(int i=0;i<s.size();i++)
        {
            if(st.empty())
            {
                if(s[i]=='(' || s[i]=='{' || s[i]=='[')
                    st.push(s[i]);
                else 
                    return false;
            }
            else 
            {
                if(s[i]=='(' || s[i]=='{' || s[i]=='[')
                    st.push(s[i]);
                else if(st.top()=='(' && s[i]==')' || st.top()=='{' && s[i]=='}' || st.top()=='[' && s[i]==']')
                    st.pop();
                else 
                    return false;
            }
        }
        if(st.size()==0)
            return true;
        return false;

        
    }
};