/**
 * @param {Node} head
 * @returns {Node}
 */

/*
class Node{
    constructor(data){
        this.data = data;
        this.next = null;
    }
}
*/

class Solution {
    // Function to remove duplicates from unsorted linked list.
    removeDuplicates(head) {
        // your code here
        let f = new Map();
        let prev = null;
        let curr = head;
        while(curr){
            if(f.has(curr.data)){
                prev.next = curr.next;
                curr = prev.next;
            }else{
                f.set(curr.data,1);
                prev = curr;
                curr = curr.next;
            }
        }
        return head;
    }
}