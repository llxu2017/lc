class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int left=0;
        int right=n-1;
        
        while(left<=right)
        {
            int mid=left+(right-left) / 2;
            if(target==nums[mid])
                return mid;
            else if(target<nums[mid])
            {
                if(mid>0)
                {
                    if(target>nums[mid-1])
                        return mid;
                    else
                        right=mid-1;
                }
                else
                    return 0;
            }
            else // target>nums[mid]
            {
                if(mid<n-1)
                {
                    if(target<nums[mid+1])
                        return mid+1;
                    else
                        left=mid+1;
                }
                else
                    return n;
            }
        }
        return -1;
    }
};
