class Solution {
public:
    const int LOG = 30;

    unordered_map<TreeNode*, vector<TreeNode*>> up;
    unordered_map<TreeNode*, int> depth;

    void dfs(TreeNode* node, TreeNode* parent) {
        if (!node) return;

        up[node] = vector<TreeNode*>(LOG, nullptr);
        up[node][0] = parent;

        depth[node] = parent ? depth[parent] + 1 : 0;

        for (int j = 1; j < LOG; j++) {
            TreeNode* mid = up[node][j - 1];

            if (mid)
                up[node][j] = up[mid][j - 1];
        }

        dfs(node->left, node);
        dfs(node->right, node);
    }

    TreeNode* lca(TreeNode* a, TreeNode* b) {
        if (depth[a] < depth[b])
            swap(a, b);

        int diff = depth[a] - depth[b];

        for (int j = 0; j < LOG; j++) {
            if (diff & (1 << j))
                a = up[a][j];
        }

        if (a == b)
            return a;

        for (int j = LOG - 1; j >= 0; j--) {
            if (up[a][j] != up[b][j]) {
                a = up[a][j];
                b = up[b][j];
            }
        }

        return up[a][0];
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, nullptr);
        return lca(p, q);
    }
};