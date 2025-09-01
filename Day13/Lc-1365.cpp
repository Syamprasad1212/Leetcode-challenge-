class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int>copy=nums;
        sort(copy.begin(),copy.end());
        unordered_map<int,int>sm;
        for(int i=0;i<copy.size();i++)
            {
             if(sm.find(copy[i])==sm.end())
                {
                    sm[copy[i]]=i;
                }
            }
        vector<int>res;
        for(int n:nums)
            {
                res.push_back(sm[n]);
            }
        return res;
    }
};
