class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string>seen,repeated;
        vector<string>result;
        if(s.size()<10)
        {
            return result;
        }
        for(int i=0;i<s.size()-9;i++)
            {
               string sub=s.substr(i,10);
                if(seen.count(sub))
                {
                    repeated.insert(sub);
                }
                else{
                    seen.insert(sub);
                }
            }
        return vector<string>(repeated.begin(),repeated.end());
    }
};
