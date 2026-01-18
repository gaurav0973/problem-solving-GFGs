/**
 * @param {Node} root
 * @param {number} n1
 * @param {number} n2
 * @returns {Node}
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
    solve(root, x, y){
        if(root == null)
            return root;
        if(root.data == x || root.data == y)
            return root;
        
        let l = this.solve(root.left, x, y);
        let r = this.solve(root.right, x, y);
        
        if(l && r)
            return root;
        
        return l != null ? l : r;
    }
    lca(root, n1, n2) {
        // code here
        return this.solve(root, n1, n2);
    }
}