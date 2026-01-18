/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};
*/
class Solution {
  public:
    bool solve(Node *root1, Node* root2){
        if(!root1 && !root2)
            return true;
        if(!root1 && root2)
            return false;
        if(!root2 && root1)
            return false;
        if(root1->data != root2->data)
            return false;
        return solve(root1->left, root2->left) && solve(root1->right, root2->right); 
    }
    bool isIdentical(Node* r1, Node* r2) {
        // code here
        return solve(r1, r2);
    }
};