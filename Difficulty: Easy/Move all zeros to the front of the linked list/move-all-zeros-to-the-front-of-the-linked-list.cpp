/* Linked List Node structure
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/
class Solution {
public:
    void moveZeroes(struct Node*& head) {
        if(!head) return;
        
        
        Node* zeroHead = nullptr;
        Node* zeroTail = nullptr;

        Node* nonZeroHead = nullptr;
        Node* nonZeroTail = nullptr;

        Node* curr = head;

        while(curr) {
            Node* nextNode = curr->next;
            curr->next = nullptr;

            if(curr->data == 0) {
                if(!zeroHead) {
                    zeroHead = curr;
                    zeroTail = curr;
                } else {
                    zeroTail->next = curr;
                    zeroTail = curr;
                }
            } else {
                if(!nonZeroHead) {
                    nonZeroHead = curr;
                    nonZeroTail = curr;
                } else {
                    nonZeroTail->next = curr;
                    nonZeroTail = curr;
                }
            }

            curr = nextNode;
        }

        if(zeroHead) {
            head = zeroHead;
            zeroTail->next = nonZeroHead;
        } else {
            head = nonZeroHead;
        }
    }
};
