// User function Template for javascript
class Solution {
    // Function to check if the given array forms an arithmetic progression
    checkIsAP(arr) {
        arr.sort((a, b) => a - b);
        let commonDiff = arr[1]- arr[0];
        for(let i=1; i<arr.length; i++){
            let d = arr[i] - arr[i-1];
            if(d !== commonDiff)
                return false;
        }
        return true;
    }
}