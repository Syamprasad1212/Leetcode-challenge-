class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        int score = 0;

        for (char c : s) {
            if (c == '(') {
                st.push(score);
                score = 0;
            } else {
                int prev = st.top();
                st.pop();
                score = prev + max(2 * score, 1);
            }
        }

        return score;
    }
};
