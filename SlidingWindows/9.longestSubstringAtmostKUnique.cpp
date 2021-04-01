/**
 * Problem: Leetcode 340 [ medium ]
 * Approach: Create a map, and this will count the unique characters. Since we have to find atmost K chars, 
 * that means, <=k case will work, and not strictly k. That'w why we only have if and else condition.
*/

#include<bits/stdc++.h>
using namespace std;
int lengthOfLongestSubstringKDistinct(string s,int k)
{
    int n = s.length();
    int i = 0, j = 0;
    map<char, int> mp;
    int mx = -1;
    while(i<=j && j<n)
    {
        mp[s[j]]++;
        if(mp.size()<=k)
        {
            mx = max(mx, (j - i + 1));
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
            if(mp.size()==k)
                mx = max(mx, (j - i + 1));
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
    int res = lengthOfLongestSubstringKDistinct(s, k);
}