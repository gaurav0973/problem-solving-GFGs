/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number[]}
 */
class Solution {
    maxOfSubarrays(arr, k) {
        // code here
        let dq = [];
        let l = 0, r = 0;
        let ans = [];
        while(r < arr.length){
            
            while (dq.length > 0 && arr[r] > arr[dq[dq.length - 1]])
                dq.pop();
            dq.push(r);
            
            while(r-l+1 > k){
                if(dq[0] <= l)
                    dq.shift();
                l++;
            }
            
            if(r-l+1 == k){
                ans.push(arr[dq[0]]);
            }
            r++;
        }
        return ans;
    }
}