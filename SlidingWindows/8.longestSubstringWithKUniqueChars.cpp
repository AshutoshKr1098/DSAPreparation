/**
 * Problem: We need to find longest substring, with K unique characters
 * Approach: We will use a map, and as soon as the map's size hits K, we will consider it as a valid candidate
 * 
*/
#include<bits/stdc++.h>
using namespace std;
int longestKSubstr(string s, int k)
{
    int i=0,j=0;
    map<char,int>mp;
    int n = s.length();
    int mx=-1;
    while(i<=j && j<n)
    {
        mp[s[j]]++;
        if(mp.size()<k)
            j++;
        else if(mp.size()==k)
        {
            mx = max(mx,j-i+1);
            j++;
        }
        else
        {
            while(i<=j && mp.size()>k)
            {
                mp[s[i]]--;
                if(mp[s[i]]==0)
                    mp.erase(s[i]);
                i++;
            }
            //In variable length sliding window problem, this step is very important as it will miss the case 
            //since we will increase our j. Thus after exiting while loop, we must check an equal condition.
            if(mp.size()==k)
                mx=max(mx,j-i+1);
            j++;
        }
        
    }
    return mx;
}
    
int main()
{
    string s;
    cin >> s;
    int k;
    cin >> k;
    int res = longestKSubstr(s, k);
}