#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    priority_queue<int> pq;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        pq.push(x);
        //Restricting the heap size to K, because we are concerned with K top elements only.
        if(pq.size()>k)
            pq.pop();
    }
    //This returns the Kth smallest
    cout << pq.top() << endl;
    //If you want to find all K smallest elements, just go around popping the pq, and storing the pq.top() 
    //somwhere
    return 0;
}