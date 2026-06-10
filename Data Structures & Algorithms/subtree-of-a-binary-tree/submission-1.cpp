class Solution {
public:
    bool same(TreeNode* a, TreeNode* b) {
        if (a == NULL && b == NULL) {
            return true;
        }

        if (a == NULL || b == NULL) {
            return false;
        }

        return a->val == b->val &&
               same(a->left, b->left) &&
               same(a->right, b->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) {
            return false;
        }

        if (same(root, subRoot)) {
            return true;
        }

        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};