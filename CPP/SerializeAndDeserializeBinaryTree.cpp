/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        serializeToSS(root, out);
        cout<<out.str();
        return out.str();
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserializeFromSS(in);
    }
    
private:
    void serializeToSS(TreeNode *root, ostringstream& out) {
        if (root == NULL) out<<"# ";
        else {
            out<<root->val;
            if (root->left != NULL || root->right != NULL) {
                out<<" , ";
                serializeToSS(root->left, out);
                serializeToSS(root->right, out);
            }
            else out<<" ; ";
        }
    }
    
    TreeNode * deserializeFromSS(istringstream& in) {
        string val;
        in>>val;
        if (val == "#") return NULL;
        else {
            TreeNode* root = new TreeNode(stoi(val));
            in>>val;
            if (val == ",") {
                root->left = deserializeFromSS(in);
                root->right = deserializeFromSS(in);
            }
            return root;
        }
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));