// User function Template for javascript

class Solution {
    countPairs(arr1, arr2, x) {
        // code here
        let f = new Map();
        
        for (let i = 0; i < arr1.length; i++) {
            f.set(arr1[i], true);
        }
        
        let cnt = 0;
        for(let i=0; i<arr2.length; i++){
            let y = x - arr2[i];
            if(f.has(y))
                cnt++;
        }
        return cnt;
    }
}
