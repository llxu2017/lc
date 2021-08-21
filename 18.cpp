class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums, int start, int end, int t) {
        vector<vector<int>> r;
        
        for(int i=start;i<=end-2;++i)
        {
            if(i!=start&&nums[i-1]==nums[i]) continue;
            int j=i+1;
            int k=end;
            int target=t-nums[i];
            while(j<k)
            {
                int sum=nums[j]+nums[k];
                if(sum==target)
                {
                    r.push_back({nums[i], nums[j], nums[k]});
                    while(j<k&&nums[j]==nums[j+1]) ++j;
                    while(j<k&&nums[k]==nums[k-1]) --k;
                    ++j;
                    --k;
                }
                else if(sum>target)
                    --k;
                else
                    ++j;
            }
        }
        return r;
    }    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> r;
        int n=nums.size()-1;
        sort(nums.begin(), nums.end());
        for(int i=0;i<=n-3;++i)
        {
            if(i!=0&&nums[i-1]==nums[i]) continue;
            auto t=threeSum(nums, i+1, n, target-nums[i]);
            for(auto& elem:t)
            {
                vector<int> sol;
                sol.push_back(nums[i]);
                sol.insert(sol.end(), elem.begin(), elem.end());
                r.push_back(sol);
            }
        }
        
        return r;
    }
};
