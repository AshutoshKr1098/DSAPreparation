/*
 * Problem: Sliding Window median
 * Difficulty: hard 
 * Key points: Solved it on my own, using the concept learnt in Median in Continuous stream.
    Approach: Use 2 heaps, but since this is a sliding window problem, thus as soon as an element gets out of the window, we will need to remove it from current heap as well. But, priority queue sadly does not support the delete operation for any random element, thus we are using a multiset(a set can be used as well if we promise to not give duplicate numbers)
    Min Heap -> Multiset
    Max Heap -> Multiset with greater int comparator

    Steps: 
    1. Just like any fixed length sliding window, perform the action with that element. In our case, we need to decide what heap to insert the element in, and after insertion balance the heaps.
    2. Next, check if window is hit, if not then j++
    3. If window is hit, then perform the task as required. We check if either of heap's size is bigger than other. If so then median is part of that heap. Else median is calculated using top of both the heaps.
    4. Now, we slide our window, and delete the element if it exists in either of the heap.
    5. Finally we balance the heaps again
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int abs(int x)
    {
        return x<0?x*-1:x;
    }
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int>mn;
        multiset<int,greater<int>>mx;
        int i =0,j=0;
        vector<double>res;        
        while(j<nums.size())
        {
            //perform action
            if(mx.size()==0)
                mx.insert(nums[j]);
            else if(*mx.begin()>nums[j])
                mx.insert(nums[j]);
            else 
                mn.insert(nums[j]);
            
            if(abs(mx.size()-mn.size())>1)
            {
                if(mx.size()>mn.size())
                {
                    mn.insert(*mx.begin());
                    mx.erase(mx.begin());
                }
                else
                {
                    mx.insert(*mn.begin());
                    mn.erase(mn.begin());
                }
            }
            
            if(j-i+1<k)
                j++;
            else if(j-i+1==k)
            {
                //find median
                if(mx.size()>mn.size())
                    res.push_back(*mx.begin());
                else if(mn.size()>mx.size())
                    res.push_back(*mn.begin());
                else
                {
                    long long x = (long long)*mx.begin()+*mn.begin();
                    res.push_back(x*0.5);
                }
                //erase
                if(mx.find(nums[i])!=mx.end())
                    mx.erase(mx.find(nums[i]));
                else if(mn.find(nums[i])!=mn.end())
                    mn.erase(mn.find(nums[i]));
                //balance again
                if(abs(mx.size()-mn.size())>1)
                {
                    if(mx.size()>mn.size())
                    {
                        mn.insert(*mx.begin());
                        mx.erase(mx.begin());
                    }
                    else
                    {
                        mx.insert(*mn.begin());
                        mn.erase(mn.begin());
                    }
                }
                //slide window
                i++; 
                j++;
            }            
        }
        return res;
    }
};