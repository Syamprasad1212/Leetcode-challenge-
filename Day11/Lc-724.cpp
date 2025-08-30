class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        int l=0;
        for(int i=0;i<nums.size();i++)
            {
                int r_s=sum-l-nums[i];
                if(l==r_s)
                {
                    return i;
                }
                l+=nums[i];
            }
        return -1;
    }
};
