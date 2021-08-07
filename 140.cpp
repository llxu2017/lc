class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> w;
        for(auto&wd:wordDict)
            w.insert(wd);
        
        int n=s.length();
        vector<bool> dp(n+1,false);
        dp[n]=true;
        helper(s,w,dp);
        return parse(s, 0, w, dp);
    }
    
    vector<string> parse(string&s, int start, unordered_set<string>& w, vector<bool>& dp)
    {
        int n=s.length();
        if(start==n) return vector<string>{};
        string t;
        vector<string> r;
        for(int i=start;i<n;++i)
        {
            t+=s[i];
            if(w.count(t)&&dp[i+1])
            {
                vector<string> next=parse(s,i+1,w,dp);
                if(next.empty())
                    r.push_back(t);
                else
                {
                    for(auto&n:next)
                    {
                        r.push_back(t+string(" ")+n);
                    }
                }
            }
        }
        return r;
    }
    
    void helper(string& s, unordered_set<string>& words, vector<bool>& dp)
    {
        int n=s.length();
        for(int i=n-1;i>=0;--i)
        {
            string t;
            for(int j=i;j<n;++j)
            {
                t+=s[j];
                if(words.count(t)&&dp[j+1])
                {
                    dp[i]=true;
                }
            }
        }
    }
};
