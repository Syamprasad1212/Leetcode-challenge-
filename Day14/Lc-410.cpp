class Solution {
public:
    bool canSplit(vector<int>& nums, int m, int mid) {
        int count = 1;      // at least one subarray
        long long sum = 0;  
        for (int n : nums) {
            if (sum + n > mid) {  // need new subarray
                count++;
                sum = n;
                if (count > m) return false; // too many splits
            } else {
                sum += n;
            }
        }
        return true;
    }

    int splitArray(vector<int>& nums, int m) {
        int left = *max_element(nums.begin(), nums.end()); // min possible
        long long right = accumulate(nums.begin(), nums.end(), 0LL); // max possible
        int ans = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canSplit(nums, m, mid)) {
                ans = mid;       // valid → try smaller
                right = mid - 1;
            } else {
                left = mid + 1;  // not valid → increase limit
            }
        }
        return ans;
    }
};
