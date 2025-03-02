class Solution {
public:
    int count = 0;

    int kthSmallest(TreeNode* root, int k) {
        TreeNode* result = helper(root, k);
        return result ? result->val : 0;
    }

    TreeNode* helper(TreeNode* root, int k) {
        if (root == nullptr) return nullptr;

        TreeNode* left = helper(root->left, k);
        if (left != nullptr) return left;
        count++; // Increment count for current node
        if (count == k) return root; 

        return helper(root->right, k);
    }
};