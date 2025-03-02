class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return NULL;

        Node* leftmost = root;

        while(leftmost->left){
            Node* cur = leftmost;

            while(cur){
                cur->left->next = cur->right;

                if(cur->next){
                    cur->right->next = cur->next->left;
                }

                cur = cur->next;
            }

            leftmost = leftmost->left;
        }

        return root;
    }
};