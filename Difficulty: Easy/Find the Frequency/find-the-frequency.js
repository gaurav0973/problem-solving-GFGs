/**
 * @param {number[]} arr
 * @param {number} x
 * @returns { number}
 */

class Solution {
    findFrequency(arr, x) {
        // code here
        let cnt = 0;
        for(let i=0; i<arr.length; i++){
            if(arr[i] === x)
                cnt++;
        }
        return cnt;
    }
}