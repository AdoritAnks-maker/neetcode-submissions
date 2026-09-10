class Solution {
public:

    TreeNode* findMax(TreeNode* root) {
        while(root->right != NULL) {
            root = root->right;
        }
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;

        if(key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        else if(key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        else {
        
            if(!root->left && !root->right) {
                delete root;
                return NULL;
            }
            if(!root->left) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            if(!root->right) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

     
            TreeNode* temp = findMax(root->left);
            root->val = temp->val;
            root->left = deleteNode(root->left, temp->val);
        }

        return root;
    }
};