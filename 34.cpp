class Solution {
public:
    int bsearch(vector<int>& nums, int left, int right, int target, bool sleft)
    {
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(nums[mid]==target)
            {
                if(sleft)
                {
                    if(mid==0)
                        return mid;
                    else
                    {
                        if(target>nums[mid-1])
                            return mid;
                        else
                            right=mid-1;
                    }
                }
                else // right
                {
                    if(mid==nums.size()-1)
                        return mid;
                    else
                    {
                        if(target<nums[mid+1])
                            return mid;
                        else
                            left=mid+1;
                    }                    
                }
            }
            else if(nums[mid]<target)
                left=mid+1;
            else
                right=mid-1;
        }
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int l=-1;
        int r=-1;
        int left=0;
        int right=nums.size()-1;
        l=bsearch(nums, left, right, target, true);
        r=bsearch(nums, left, right, target, false);
        return vector<int>{l,r};
    }
};
