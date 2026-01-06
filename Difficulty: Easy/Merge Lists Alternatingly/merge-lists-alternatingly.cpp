/*
structure of the node of the linked list is
struct Node
{
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/
// Function to merge two linked lists
class Solution {
public:
    vector<Node *> mergeList(struct Node **head1, struct Node **head2) {
        if(!head1 || !head2) {
            return {*head1, *head2};
        }

        Node *t1 = *head1;
        Node *t2 = *head2;

        while(t1 && t2) {
            Node *t1Next = t1->next;
            Node *t2Next = t2->next;

            t1->next = t2;
            t2->next = t1Next;

            t1 = t1Next;
            t2 = t2Next;
        }

        return {*head1, t2};
    }
};
