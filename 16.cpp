class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
        int diff=INT_MAX;
        int s=0;
        int n=nums.size();
        
        for(int i=0; i<n-2;++i)
        {
            if(i>0&&nums[i]==nums[i-1]) continue;
            
            int t=target-nums[i];
            
            int j=i+1;
            int k=n-1;
            
            while(j<k)
            {
                if(t==nums[j]+nums[k])
                    return target;
                else if(t<nums[j]+nums[k])
                {
                    int ss=nums[i]+nums[j]+nums[k];
                    int d=ss-target;
                    if(abs(d)<diff)
                    {
                        s=ss;
                        diff=abs(d);
                    }
                    while(j<k&&nums[k]==nums[k-1]) --k;
                    --k;
                }
                else
                {
                    int ss=nums[i]+nums[j]+nums[k];
                    int d=ss-target;
                    if(abs(d)<diff)
                    {
                        s=ss;
                        diff=abs(d);
                    }
                    while(j<k&&nums[j]==nums[j+1]) ++j;
                    ++j;                
                }
            }
        }
        
        return s;
    }
};
