// User function Template for javascript

/**
 * @param {number[]} arr
 * @param {number} sum
 * @return {number}
 */

class Solution {
    findMaxSubarraySum(arr, x) {
        // code here
        let n = arr.length;
        let l = 0;
        let r = 0;
        let sum = 0;
        let ans = 0;
        while(r < n){
            sum += arr[r];
            while(sum > x){
                sum -= arr[l];
                l++;
            }
            ans = Math.max(ans, sum);
            r++;
        }
        return ans;
    }
}