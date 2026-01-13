// User function Template for javascript

/**
 * @param {string} s
 * @return {string}
 */
class Solution {
    firstRep(s) {
        // First pass: count fuency of each character
        let f = new Map();
        
        for (let i = 0; i < s.length; i++) {
            f.set(s[i], (f.get(s[i]) || 0) + 1);
        }
        
        // Second pass: find first character with fuency > 1
        for (let i = 0; i < s.length; i++) {
            if (f.get(s[i]) > 1) {
                return s[i];
            }
        }
        
        return -1;
    }
}
