class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size()-1;
        if(n==0) return 0;
        
        bool left=height[0]<height[n];
        int i=0;
        int j=n;
        int total=n*min(height[0], height[n]);
        while(i<j)
        {
            if(left)
            {
                int k=i;
                while(k<j && height[k]<=height[i])
                    ++k;
                total=max(total, (j-k)*min(height[k],height[j]));
                left=height[k]<height[j];
                i=k;
            }
            else
            {
                int k=j;
                while(k>i && height[k]<=height[j])
                    --k;
                total=max(total, (k-i)*min(height[k],height[i]));
                left=height[i]<height[k];
                j=k;
            }
        }
        return total;
    }
};
