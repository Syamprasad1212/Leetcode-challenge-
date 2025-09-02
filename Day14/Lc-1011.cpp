class Solution {
public:
    bool canShip(vector<int>& weights, int days, int capacity) {
        int usedDays = 1;   // start with day 1
        int currentLoad = 0;
        for(int w : weights) {
            if(currentLoad + w > capacity) {
                usedDays++;        // need another day
                currentLoad = 0;   // reset load
            }
            currentLoad += w;
        }
        return usedDays <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end()); // biggest single package
        int high = accumulate(weights.begin(), weights.end(), 0); // all in one day
        int result = high;

        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(canShip(weights, days, mid)) {
                result = mid;   // possible, try smaller
                high = mid - 1;
            } else {
                low = mid + 1; // not possible, need bigger capacity
            }
        }
        return result;
    }
};
