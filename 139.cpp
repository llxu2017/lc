class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> w;
        for(auto&wd:wordDict)
            w.insert(wd);
        return helper(s,w);
    }
    
    bool helper(string& s, unordered_set<string>& words)
    {
        int n=s.length();
        vector<bool> dp(n+1,false);
        dp[n]=true;
        for(int i=n-1;i>=0;--i)
        {
            string t;
            for(int j=i;j<n;++j)
            {
                t+=s[j];
                if(words.count(t)&&dp[j+1])
                {
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[0];
    }
};
