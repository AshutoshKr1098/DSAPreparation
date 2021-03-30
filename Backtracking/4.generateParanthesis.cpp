#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int cnt = 0;
    vector<string> paranthesis;
    string res = "";
    gp(0,0, 0, res, n, paranthesis);
    for(auto it:paranthesis)
        cout << it << endl;
}