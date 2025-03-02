class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result = {};
        vector<int> level = {};
        queue<TreeNode*> q;
        q.push(root);

        int l = 1;
        int i = 0;
        int nullCount = 0;
        while (!q.empty()) {
            TreeNode * temp = q.front();
            q.pop();
            if (temp) {
                level.push_back(temp->val);
                q.push(temp->left);
                q.push(temp->right);
            } else {
                nullCount++;
            }
            i++;
            if (i == l) {
                l = l*2;
                l = l - 2 * nullCount;
                nullCount = 0;
                i = 0;
                if (!level.empty()) {
                    result.push_back(level);
                }
                level.clear();
            }
        }
        return result;
    }
};