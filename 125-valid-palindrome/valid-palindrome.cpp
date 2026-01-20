class Solution {
public:
    bool isPalindrome(string s) {
        queue<char> q;
        stack<char> st;

        for (char c : s) {
            if (isalpha(c)||isdigit(c)) {
                char x = tolower(c);
                q.push(x);
                st.push(x);
            }
        }

        while (!q.empty()) {
            if (q.front() != st.top()) {
                return false;
            }
            q.pop();
            st.pop();
        }

        return true;
    }
};