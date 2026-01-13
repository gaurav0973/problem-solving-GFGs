class Solution {
    findUnique(k, arr) {
        // Code here
        let f = new Map();
        for(let i=0; i<arr.length; i++){
            f.set(arr[i], (f.get(arr[i]) || 0) + 1);
        }
        
        for(let [key, value] of f){
            if(value%k != 0)
                return key;
        }
        return -1;
    }
}
