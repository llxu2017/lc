class Solution {
public:
    void helper(vector<int>& c, vector<vector<int>>& r, vector<int>& b, int start, int target)
    {
        int n=c.size();
        if(target==0)
        {
            r.push_back(b);
            return;
        }
        else if(start==n || target<0)
            return;
        
        int pre=-1;
        for(int i=start;i<n;++i)
        {
            if(c[i]!=pre)
            {
                b.push_back(c[i]);
                helper(c,r,b,i+1,target-c[i]);
                pre=c[i];
                b.pop_back();
            }
           
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> r;
        vector<int> b;
        helper(candidates, r, b, 0, target);
        return r;
    }
};
