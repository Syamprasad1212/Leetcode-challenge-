class Solution {
public:
    int calculate(string s) {
        int i = 0;
        return eval(s, i);
    }

private:
    int eval(string& s, int& i) {
        stack<int> st;
        long num = 0;
        char sign = '+';

        while (i < s.size()) {
            char c = s[i];
            if (isdigit(c)) num = num * 10 + (c - '0');
            if (c == '(') { i++; num = eval(s, i); }
            if ((!isdigit(c) && c != ' ' && c != '(') || i == s.size() - 1) {
                if (sign == '+') st.push(num);
                else if (sign == '-') st.push(-num);
                else if (sign == '*') { int top = st.top(); st.pop(); st.push(top * num); }
                else if (sign == '/') { int top = st.top(); st.pop(); st.push(top / num); }
                sign = c; num = 0;
            }
            if (c == ')') break;
            i++;
        }
        int sum = 0;
        while (!st.empty()) { sum += st.top(); st.pop(); }
        return sum;
    }
};
