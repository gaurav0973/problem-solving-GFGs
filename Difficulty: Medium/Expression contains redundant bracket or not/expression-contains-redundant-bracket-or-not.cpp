class Solution {
  public:
    bool checkRedundancy(string &s) {
        stack<char> st;
        
        for (char ch : s) {
            if (ch != ')') {
                st.push(ch);
            } else {
                // Found closing bracket
                bool hasOperator = false;
                
                // Pop until matching '('
                while (!st.empty() && st.top() != '(') {
                    char top = st.top();
                    if (top == '+' || top == '-' || top == '*' || top == '/') {
                        hasOperator = true;
                    }
                    st.pop();
                }
                
                // Pop the '('
                if (!st.empty()) st.pop();
                
                // If no operator found between brackets, it's redundant
                if (!hasOperator) {
                    return true;
                }
            }
        }
        
        return false;
    }
};