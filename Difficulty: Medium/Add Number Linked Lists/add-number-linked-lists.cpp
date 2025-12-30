/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    Node *reverseLL(Node *head){
        Node *curr = head;
        Node *prev = nullptr;
        while(curr){
            Node *curr_next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = curr_next;
        }
        return prev;
    }
    
    Node* addTwoLists(Node* num1, Node* num2) {
        
        
        Node *node1 = reverseLL(num1);
        Node *node2 = reverseLL(num2);
        
        Node *tail = new Node(-1);
        Node *dummy = tail;
        
        int carry = 0;
        while(node1 || node2 || carry){
            long sum = carry;
            
            if(node1){
                sum += node1->data;
                node1 = node1->next;
            }
            if(node2){
                sum += node2->data;
                node2 = node2->next;
            }
            
            tail->next = new Node(sum%10);
            carry = sum/10;
            tail = tail ->next;
            
        }
        
        // removing the leading zero 
        Node *head = reverseLL(dummy->next);
        delete dummy;
        
        while(head->data == 0 && head->next){
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        
        return head;
        
    }
};