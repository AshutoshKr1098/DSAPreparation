#include<bits/stdc++.h>
using namespace std;


void printPath(vector<vector<int>>&visited)
{
    for(auto it:visited)
    {
        for(auto x:it)
            cout << x << " ";
        cout << endl;
    }
    cout << endl;
    return;
}
void rim(vector<vector<int>>&maze,int x,int y,int n,vector<vector<int>>&visited)
{
    if(x>=n || x<0 || y>=n || y<0 || maze[x][y]==0 || visited[x][y]==true)
        return;
    if(x==n-1 && y==n-1)
    {
        visited[x][y] = true;
        printPath(visited);
        visited[x][y] = false;
        return;
    }
    visited[x][y] = true;
    rim(maze, x - 1, y,n, visited);
    rim(maze,x,y+1,n, visited);
    rim(maze,x+1,y,n, visited);
    rim(maze,x,y-1,n, visited);
    visited[x][y] = false;
    return;
}
int main()
{
    vector<vector<int>> maze;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            temp.push_back(x);
        }
        maze.push_back(temp);
    }
    vector<vector<int>> visited;
    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        for (int j = 0; j < n; j++)
        {            
            temp.push_back(0);
        }
        visited.push_back(temp);
    }
    rim(maze, 0, 0,n, visited);
}