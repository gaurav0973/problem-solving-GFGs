/**
 * @param {Node} root
 * @returns {number}
 */

/*
class Node{
    constructor(data){
        this.data = data;
        this.left = null;
        this.right = null;
    }
}
*/

class Solution {
    getMaxSum(root) {
        let ans = this.solve(root);
        return Math.max(ans.take, ans.notTake);
    }
    
    solve(root){
        if (!root)
            return { take: 0, notTake: 0 };
        
        let l = this.solve(root.left);
        let r = this.solve(root.right);
        
        let take = root.data + l.notTake + r.notTake;
        let notTake =
            Math.max(l.take, l.notTake) +
            Math.max(r.take, r.notTake);
        
        return { take, notTake };
    }
}
