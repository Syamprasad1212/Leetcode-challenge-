class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> path;
        backtrack(candidates, target, 0, path, res);
        return res;
    }

    void backtrack(vector<int>& nums, int target, int start, vector<int>& path, vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(path);
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i-1]) continue;  
            if (nums[i] > target) break;  

            path.push_back(nums[i]);
            backtrack(nums, target - nums[i], i + 1, path, res);
            path.pop_back();
        }
    }
};
