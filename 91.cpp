class Solution {
public:
    int numDecodings(string s) {
        int n=s.length();
        vector<int> dp(n+1,-1);
        return helper(s, 0, dp);
    }
    
    int helper(string&s, int i, vector<int>& dp)
    {
        int n=s.length();
        if(dp[i]!=-1) return dp[i];
        if(i==n) return dp[n]=1;
        else if(s[i]=='0') return dp[i]=0;
        else if(s[i]=='1')
        {
            int total=helper(s, i+1, dp);
            if(i+1<n)
                total+=helper(s, i+2, dp);
            return dp[i]=total;
        }
        else if(s[i]=='2')
        {
            int total=helper(s, i+1, dp);
            if(i+1<n&&s[i+1]<'7')
                total+=helper(s, i+2, dp);
            return dp[i]=total;
        }
        else // '3'~'9'
        {
            return dp[i]=helper(s,i+1,dp);
        }
    }
};
