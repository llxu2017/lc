class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(!nums.size()) return 0;
        
        int i=0;
        int j=0;
        while(j<nums.size())
        {
            if(nums[j]!=val)
            {
                nums[i]=nums[j];
                ++i;
            }
            ++j;
        }
        return i;
    }
};
