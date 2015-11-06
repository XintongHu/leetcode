/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL)
            return;
        TreeLinkNode *tmp = root, *prev = NULL, *l;
        while (tmp != NULL) {
            l = tmp;
            while (prev != NULL) {
                if (tmp == prev->left) {
                    tmp->next = prev->right;
                    tmp = tmp->next;
                    prev = prev->next;
                }
                else {
                    tmp->next = prev->left;
                    tmp = tmp->next;
                }
            }
            tmp->next = prev;
            prev = l;
            tmp = l->left;
        }
    }
};