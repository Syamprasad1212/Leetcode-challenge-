class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>>st;
        for(char ch:s)
            {
                if(!st.empty()&&st.top().first==ch)
                    {
                        st.top().second++;
                    
                if(st.top().second==k)
                {
                    st.pop();
                }
                    }
                else{
                    st.push({ch,1});
                }
            }
        string result="";
        while(!st.empty())
            {
                auto[c,cnt]=st.top();
                st.pop();
                result.append(cnt,c);
            }
        reverse(result.begin(),result.end());
        return result;
    }
};
