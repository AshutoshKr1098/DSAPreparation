/**
 * Problem: Leetcode #1456 [Medium]
 * Approach: Solved using classical way of solving fixed size window problem, just keep track of vowels.
*/
#include<bits/stdc++.h>
using namespace std;
int maxVowelInWindowK(string s, int k)
{

    int i = 0, j = 0, vowels = 0;
    int maxVowels = INT_MIN;
    while (j < s.size())
    {
        if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u')
            vowels++;
        if (j - i + 1 < k)
            j++;
        else if (j - i + 1 == k)
        {
            maxVowels = max(vowels, maxVowels);
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
                vowels--;
            i++;
            j++;
        }
    }
    return maxVowels;
}
int main()
{
    string s;
    int k;
    cin >> s >> k;
    cout << maxVowelInWindowK(s,k)<< endl;
}