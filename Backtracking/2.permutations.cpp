#include<bits/stdc++.h>
using namespace std;
void permute(string &s,int start,vector<string>&res)
{
    if(start==s.size())
        return;
    if(start==s.size()-1)
    {
        res.push_back(s);
        return;        
    }
    for (int i = start; i<s.size(); i++)
    {
        //do
        swap(s[i], s[start]);
        //recurse now
        permute(s, start + 1, res);
        //undo
        swap(s[i], s[start]);
    }
    return;
}
int main()
{
    string s;
    cin >> s;
    vector<string> res;
    permute(s, 0, res);
    cout << res.size() << endl;
    set<string> st;
    for (auto it : res)
    {
        st.insert(it);
    }
    for(auto it:st)
        cout << it << " ";
    cout << endl;
    return 0;
}