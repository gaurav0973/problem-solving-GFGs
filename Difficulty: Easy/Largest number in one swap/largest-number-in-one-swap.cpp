class Solution {
  public:
    string largestSwap(string &s) {
        int n = s.size();
        vector<int> last(10, -1);
        
        // Store last occurrence of each digit
        for (int i = 0; i < n; i++) {
            last[s[i] - '0'] = i;
        }
        
        // Traverse the string
        for (int i = 0; i < n; i++) {
            int cur = s[i] - '0';
            // Check from largest digit down to cur+1
            for (int d = 9; d > cur; d--) {
                if (last[d] > i) { // if larger digit exists later
                    swap(s[i], s[last[d]]);
                    return s;  // only one swap allowed
                }
            }
        }
        return s; // already the largest
    }
};
