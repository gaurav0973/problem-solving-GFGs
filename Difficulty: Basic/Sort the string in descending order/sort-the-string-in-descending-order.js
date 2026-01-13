// User function Template for javascript
/**
 * @param {string} s
 * @returns {string}
 */

class Solution {
    ReverseSort(s) {
        // Step 1: Convert string to array
        let arr = s.split('');
        
        // Step 2: Sort in ascending order
        arr.sort();
        
        // Step 3: Reverse to get descending order
        arr.reverse();
        
        // Step 4: Convert back to string
        return arr.join('');
    }
}