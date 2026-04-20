/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return nullptr;

        int curr = root->val;

        // both nodes lie in right subtree
        if (curr < p->val && curr < q->val)
            return lowestCommonAncestor(root->right, p, q);

        // both nodes lie in left subtree
        if (curr > p->val && curr > q->val)
            return lowestCommonAncestor(root->left, p, q);

        // nodes are on different sides OR one equals root
        return  root;
    }
};
