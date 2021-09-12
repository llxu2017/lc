class Solution {
public:
    
    void helper(vector<int>& c, vector<vector<int>>& r, vector<int>& b, int target, int start)
    {
        int n=c.size();
        if(target==0)
        {
            r.push_back(b);
            return;
        }
        if(start==n)
            return;
        
        for(int i=start;i<n;++i)
        {
            if (c[i] <= target)
            {
                b.push_back(c[i]);
                target -= c[i];
                helper(c, r, b, target, i);
                b.pop_back();
                target += c[i];
            }
            else
                return;
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> r;
        vector<int> b;
        helper(candidates, r, b, target, 0);
        return r;
    }
};
