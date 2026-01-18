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
    diameter(root) {
        // code here
        this.ans = 0;
        this.solve(root);
        return this.ans;
    }
    solve(root){
        if(root == null)
            return 0;
        
        let l = this.solve(root.left);
        let r = this.solve(root.right);
        
        this.ans = Math.max(this.ans, l + r);
        
        return Math.max(l,r) + 1;
    }
}