class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<pair<int,int>> starts;
        for (int i = 0; i < n; i++)
            starts.push_back({intervals[i][0], i});

        sort(starts.begin(), starts.end());
        vector<int> res(n, -1);

        for (int i = 0; i < n; i++) {
            int end = intervals[i][1];
            int l = 0, r = n - 1;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (starts[mid].first >= end) {
                    res[i] = starts[mid].second;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
        }
        return res;
    }
};
