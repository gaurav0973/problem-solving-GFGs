class Solution {
  public:
    string firstNonRepeating(string &s) {
        int n = s.length();
        if (n == 0) return "";
        
        // Frequency array for 26 lowercase letters
        vector<int> freq(26, 0);
        
        // Queue to maintain non-repeating characters in order
        queue<char> q;
        
        string result = "";
        
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            
            // Update frequency
            freq[ch - 'a']++;
            
            // If this is first occurrence, add to queue
            if (freq[ch - 'a'] == 1) {
                q.push(ch);
            }
            
            // Remove all characters from front which are repeating now
            while (!q.empty() && freq[q.front() - 'a'] > 1) {
                q.pop();
            }
            
            // If queue is empty, no non-repeating character
            if (q.empty()) {
                result += '#';
            } else {
                result += q.front();
            }
        }
        
        return result;
    }
};