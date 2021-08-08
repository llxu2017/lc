class Solution {
public:
    bool isP(string& s, int i, int j)
    {
        while(i<j)
        {
            if(s[i]!=s[j])
                return false;
            ++i;
            --j;
        }
        return true;
    }
    
    void helper(string&s, int start, vector<vector<string>>& r, vector<string>& t)
    {
        int n=s.length();
        if(start==n)
        {
            r.push_back(t);
            return;
        }
        for(int i=start; i<n; ++i)
        {
            if(isP(s, start, i))
            {
                t.push_back(s.substr(start, i-start+1));
                helper(s, i+1, r, t);
                t.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        int n=s.length();
        
        vector<vector<string>> r;
        vector<string> t;
        
        helper(s, 0, r, t);
        return r;    
    }
};
