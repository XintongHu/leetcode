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
    int kthSmallest(TreeNode* root, int k) {
        vector<TreeNode*> queue;
        TreeNode* tmp = root, *ans;
        while (tmp != NULL) {
            queue.push_back(tmp);
            tmp = tmp->left;
        }
        while (k > 0) {
            ans = queue.back();
            queue.pop_back();
            k--;
            tmp = ans->right;
            while (tmp != NULL) {
                queue.push_back(tmp);
                tmp = tmp->left;
            }
        }
        return ans->val;
    }
};