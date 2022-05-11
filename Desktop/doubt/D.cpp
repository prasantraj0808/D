

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:

    int wordBreak(string s, vector<string> &B) {
       
        set<string>Set;
        for(auto x:B)
        {
            Set.insert(x);
        }
        bool dp[s.length()+1];
        dp[0]=true;
        for(int len=1;len<=s.length();len++)
        {
            for(int i=0;i<len;i++)
            {
                if(dp[i] && Set.find(s.substr(i,len))!=Set.end())
                {
                  dp[len]=true;
                  break;
                }
            }
        }
        return dp[s.length()];
    }
};



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}
