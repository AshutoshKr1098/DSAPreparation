/**
 * Problem Name: Stock Span Problem
 * Approach: The problem is a slight variation to "Previous greater element" question. Here, we also need to
 *           store the indexes and if stack is empty, then store the index in resulting vector.
*/

#include<bits/stdc++.h>
using namespace std;

vector<int>stockSpanSolution(int *stocks,int days)
{
    vector<int> res;
    stack<pair<int,int>> st;
    for (int i = 0; i < days;i++)
    {
        if(st.empty())
        {
            res.push_back(i + 1);
            st.push(make_pair(stocks[i], i));            
        }
        else if(st.top().first > stocks[i])
        {
            res.push_back(i - st.top().second + 1);
            st.push(make_pair(stocks[i], i));
        }
        else
        {
            while(!st.empty() && st.top().first <= stocks[i])
                st.pop();
            if(st.empty())
            {
                res.push_back(i + 1);
                st.push(make_pair(stocks[i], i)); 
            }
            else
            {
                res.push_back(i - st.top().second + 1);
                st.push(make_pair(stocks[i], i));
            }
        }
    }
    return res;
}

int main()
{
    int days;
    cin >> days;
    int *stocks = new int[days];
    for(int i = 0; i < days;i++)
        cin>>stocks[i];
    vector<int> stockSpan = stockSpanSolution(stocks, days);
    for(auto it:stockSpan)
        cout << it << " ";
}