// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    // Code here
	    int n=grid.size(),m=grid[0].size(),len=word.length(); //grid rows// grid columns//string length
	    int di[]={0,1,1,1,0,-1,-1,-1};
	    int dj[]={1,1,0,-1,-1,-1,0,1};
	    int pos=1,flag=0,anspos=0;
	    vector<vector<int>> ans;
	    for(int i=0;i<m;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	          
	            if(word[0]==grid[i][j])
	            {
	                for(int k=0;k<8;k++)
	                {
	                     for(int p=1;p<len;p++)
	                     {
	                             if(word[p]!=grid[i+di[k]][j+dj[k]])
	                             {
	                                 flag=1;
	                                 break;
	                             }
	                     }
	                     if(flag==0)
	                     {
	                         ans[anspos].push_back(i);
	                         ans[anspos++].push_back(j);
	                         break;
	                     }
	                     
	                }
	                flag=0;
	            }
	        }
	    }
	    
	    return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
	}
	return 0;
}  // } Driver Code Ends