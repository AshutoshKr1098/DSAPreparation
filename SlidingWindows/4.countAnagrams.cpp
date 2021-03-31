/**
 * Problem: Count the number of anagrams of string "pattern" in a string "text"
 * Anagram means: ABCD = any permutation of this, the total length of string should be similar to pattern and 
 * frequency of each character must also be the same.
*/

#include<bits/stdc++.h>
using namespace std;
int countAnagrams(string txt,string ptr)
{
    //Initialized separate map for both text and patterns.
    map<char, int> txtMap;
    map<char, int> ptrMap;
    int k = ptr.size();
    for (int i = 0;i<ptr.size();i++)
        ptrMap[ptr[i]]++;

    int i = 0, j = 0, cnt = 0;
    while(j<txt.size())
    {
        //Insert in text map only if that character is present. We dont want to put any random character
        //This will make our comparison easier later on.
        if(ptrMap.find(txt[j])!=ptrMap.end())
            txtMap[txt[j]]++;
        if(j-i+1<k)
            j++;
        else if(j-i+1==k)
        {
            if(ptrMap.size()==txtMap.size())
            {
                //comparing every character's frequency. We are sure that the character in each map is same,
                //due to our constraint while putting the character in textmap. Here is what makes it easy for us.
                bool flag = false;
                for(auto it:txtMap)
                {
                    //If there is frequency mismatch, then break.
                    if(ptrMap[it.first]!=it.second)
                    {
                        flag = true;
                        break;
                    }
                }
                if(!flag)
                {
                    //cout<<i<<" "<<j<<endl; //To get the start and end of anagrams in text.
                    cnt++;
                }
            }
            //Sliding the window forward, and deleting the entry from map if it's frequency becomes 0.
            txtMap[txt[i]]--;
            if(txtMap[txt[i]]==0)
                txtMap.erase(txt[i]);
            i++;
            j++;
        }
    }
    return cnt;
}
int main()
{
    string txt, ptr;
    cin >> txt >> ptr;    
    int count = countAnagrams(txt, ptr);
    cout << count << endl;
}