class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int count=0;
        int id=(ruleKey=="type")?0:(ruleKey=="color"?1:2);
        for(auto &item:items)
            {
                if(item[id]==ruleValue)
                {
                    count++;
                }
            }
        return count;
    }
};
