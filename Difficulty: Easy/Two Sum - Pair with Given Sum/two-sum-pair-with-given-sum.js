/**
 * @param {number[]} arr
 * @param {number} target
 * @return {boolean}
 */
class Solution {
    twoSum(arr, target) {
        // code here
        let f = new Map();
        for(let i=0; i<arr.length; i++){
            let y = target - arr[i];
            if(f.has(y)){
                return true;
            }else{
                f.set(arr[i], 1);
            }
        }
        return false;
    }
}