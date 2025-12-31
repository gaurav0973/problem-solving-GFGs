/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
       data = x;
       next = NULL;
    }
};
*/

class Solution {
  public:
    
    Node* reverseList(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        
        while (curr) {
            Node* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
    
    bool isPalindrome(Node *head) {
        if (!head || !head->next) return true;
        
        // Step 1: Find middle
        Node* slow = head;
        Node* fast = head;
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Step 2: Reverse second half
        Node* secondHalf = reverseList(slow);
        Node* firstHalf = head;
        
        // Step 3: Compare both halves
        while (secondHalf) {
            if (firstHalf->data != secondHalf->data)
                return false;
            
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }
        
        return true;
    }
};
