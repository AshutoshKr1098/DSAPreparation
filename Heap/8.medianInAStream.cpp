/**
 * Problem: Median in a stream
 * Difficulty: Hard
 * Approach: 2 Heaps, one to store min of right of median, other to store max to the left of median.
 * Thus we will need a max heap and a min heap. 
 * We also need to balance the heap sizes,as soon as the difference between their sizes gets greater than 2.
 * 
 * Step1: Insert into appropriate heap. If both heaps are empty, then insert into max heap.
 * Step2: Now balance the heaps, as soon as the difference between them exceeds 1.
 * Step3: Find median. If the size differs, that means total els are odd, hence return top of higher size heap.
 * Else, calculate median using both.
*/
#include<bits/stdc++.h>
using namespace std;
class MedianFinder {
    priority_queue<int>mx;
    priority_queue<int,vector<int>,greater<int>>mn;
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    } 
    int abs(int n)
    {
        return n<0?n*-1:n;
    }
    void addNum(int num) {
        if(mx.size()==0)
            mx.push(num);
        else if(mx.top()>num)
            mx.push(num);
        else 
            mn.push(num);
        
        if(abs(mx.size()-mn.size())>1)
        {
            if(mx.size()>mn.size())
            {
                mn.push(mx.top());
                mx.pop();
            }
            else
            {
                mx.push(mn.top());
                mn.pop();
            }
        }
        
    }
    
    double findMedian()
    {
        if(mx.size()>mn.size())
            return mx.top();
        else if(mn.size()>mx.size())
            return mn.top();
        else
            return ((double)(mx.top()+mn.top())*0.5);
            
    }
};