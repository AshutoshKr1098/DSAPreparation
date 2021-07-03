// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    void fill(vector<vector<int>>&mz,int i,int j,int clr,int nc)
    {        
        //Base conditions
        if(i<0 || i>=mz.size() || j<0 || j>=mz[0].size())
            return;
        if(mz[i][j]!=clr)
            return;
        mz[i][j]=nc;
        fill(mz,i-1,j,clr,nc);
        fill(mz,i+1,j,clr,nc);
        fill(mz,i,j-1,clr,nc);
        fill(mz,i,j+1,clr,nc);
        return;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<vector<int>>mz=image;
        if(image[sr][sc]==newColor)
            return mz;
        int clr=image[sr][sc];
        int nc=newColor;
        fill(mz,sr,sc,clr,nc);
        // cout<<endl;
        return mz;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends