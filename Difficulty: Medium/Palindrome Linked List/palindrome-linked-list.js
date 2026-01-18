/**
 * @param {Node} head
 * @returns {boolean}
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
    reverse(head){
        let prev = null;
        let curr = head;
        while(curr){
            let currNext = curr.next;
            curr.next = prev;
            prev = curr;
            curr = currNext;
        }
        return prev;
    }
    isPalindrome(head) {
        // code here
        if(!head || !head.next)
            return true;
        let slow = head;
        let fast = head;
        while(fast && fast.next){
            slow = slow.next;
            fast = fast.next.next;
        }
        
        let first = head;
        let second = this.reverse(slow);
        
        while(second){
            if(first.data !== second.data)
                return false;
            first = first.next;
            second = second.next;
        }
        
        return true;
        
    }
}