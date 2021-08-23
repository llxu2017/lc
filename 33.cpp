class Solution {
public:
    int bsearch(vector<int>& nums, int left, int right, int target)
    {
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }


    int jumpsearch(vector<int>& nums, int left, int right)
    {
        if (left == right) return left;
        int mid = left + (right - left) / 2;

        if (mid == left || mid == right) return mid;

        if (nums[left] <= nums[mid] && nums[mid] <= nums[right])
            return -1;
        else if (nums[left] <= nums[mid])
            return jumpsearch(nums, mid, right);
        else
            return jumpsearch(nums, left, mid);
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size() - 1;
        int left = 0;
        int right = nums.size() - 1;

        int jump = jumpsearch(nums, left, right);
        if (jump == -1 || jump==right)
        {

        }
        else if (jump == left)
        {
            jump = 1;
        }
        else
        {
            if (nums[jump] >= nums[jump + 1])
                jump++;
        }

        if (jump == -1)
            return bsearch(nums, left, right, target);

        if (nums[left] <= target && target <= nums[jump - 1])
            return bsearch(nums, left, jump - 1, target);
        else
            return bsearch(nums, jump, right, target);


        return -1;
    }
};
