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
    TreeNode* buildHelper(vector<int>& preorder, vector<int>& inorder, int p, int q, int m) {
        TreeNode *root = NULL;
        if (q <= p) return root;
        int val = preorder[m];
        root = new TreeNode(val);
        for (int i = p; i < q; ++i) {
            if (inorder[i] == val) {
                root->left = buildHelper(preorder, inorder, p, i, m + 1);
                root->right = buildHelper(preorder, inorder, i + 1, q, i - p + m + 1);
                break;
            }
        }
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int size = inorder.size();
        return buildHelper(preorder, inorder, 0, size, 0);
    }
};