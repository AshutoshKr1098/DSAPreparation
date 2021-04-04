/**
 * Problem: Meeting Rooms 2 
 * Approach: Using Heap
 * 
 * Steps: 
 * 1. First sort the incoming vectors, since we need to know the starting times and ending time in a order. 
 * By sorting, we will have an ordered list of meetings, sorted on the basis of start time.
 * This is why, to sort it, we used priority_queue in the beginnning named sorted. 
 * 
 * 2. Once we have our sorted list of meetings, we need to start executing our logic. So our logic says,
 * we will make a min heap, and this min heap will store the schedule on basis of end time. That means, at any given time
 * we will know, what meetings have started first and whether they are still running or not. 
 * Why this step is necessary? Because, in some time in future, a meeting that started early might get finished
 * thus to know all such finished meetings(thus empty rooms) we have used a min heap.
 * 
 * Ex: [5,15],[13,30],[17,20]-> thus we will only need 2 rooms, since the meeting 5-15 ended, but we need to know it as well/
 * This is why we are storing a min heap with respect to end time.
*/
#include<bits/stdc++.h>
using namespace std;
int minMeetingRooms(vector<vector<int>>& intervals) 
{
    //Sort the vectors, on the basis of start time. To sort, we used priority queue min.
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>sorted;  
    for(auto it:intervals)
        sorted.push(make_pair(it[0],it[1])); //min heap, on the basis of start time.
    
    //this will hold the count of number of rooms
    int cnt=0;
    //Pq is storing the end time, min heap with end time as deciding factor.
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    while(!sorted.empty())
    {
        auto it = sorted.top();
        sorted.pop();
        //if the pq is empty, we will insert new vector. And if cnt is 0, that means it's our first 
        //meeting, hence increase the cnt of room. Else dont increase. Because at some point of time 
        //in future, our heap might get empty, meaning all meetings are disjoint. In that case we dont neeed
        //to increase rooms. Previous count will work.

        if (pq.empty())
        {
            pq.push(make_pair(it.second,it.first)); 
            if(cnt==0)
                cnt++;
        }
        else if(it.first<pq.top().first)
        {
            //If room is booked, then insert the pair. And if the heap size exceeds count, that means
            //we need to have a new room. Since the previous count is less. 
            pq.push(make_pair(it.second,it.first)); 
            if(cnt<pq.size())
                cnt=pq.size();
        }
        else 
        {
            //Else, if the previous meetings got over, we start popping them out. Finally we push the 
            //new meeting into heap. As an additional surity check, we also see the room count.
            while(!pq.empty() && pq.top().first<=it.first)
                pq.pop();
            pq.push(make_pair(it.second,it.first)); 
            if(cnt<pq.size())
                cnt=pq.size();
        }
    }   
    return cnt;
}
int main()
{
    vector<vector<int>> intervals;
    int n;
    cin >> n;
    for (int i = 0; i < n;i++)
    {
        vector<int> temp;
        int s, e;
        cin >> s >> e;
        temp.push_back(s);
        temp.push_back(e);
        intervals.push_back(temp);
    }
    cout << minMeetingRooms(intervals) << endl;
}