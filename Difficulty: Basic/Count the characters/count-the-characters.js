// User function Template for javascript

/**
 * @param {string} S
 * @param {number} N
 * @return {number}
 */

class Solution {
    getCount(S, N) {
        // code here
        let f = new Map();
        f.set(S[0], 1);
        let cnt = 0;
        for(let i=1; i<S.length; i++){
            if(S[i] != S[i-1])
                f.set(S[i], (f.get(S[i]) || 0) + 1);
        }
        
        for(let [key , value] of f){
            if(value === N)
                cnt++;
        }
        return cnt;
    }
}
