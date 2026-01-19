class Solution {
public:
    string removeKdig(string &s, int k) {
        string st;

        for (char c : s) {
            // remove bigger digits from back if we still can
            while (!st.empty() && k > 0 && st.back() > c) {
                st.pop_back();
                k--;
            }
            st.push_back(c);
        }

        // if k is still left, remove from end
        while (k > 0 && !st.empty()) {
            st.pop_back();
            k--;
        }

        // remove leading zeros
        int i = 0;
        while (i < st.size() && st[i] == '0') i++;

        string ans = st.substr(i);

        return ans.empty() ? "0" : ans;
    }
};
