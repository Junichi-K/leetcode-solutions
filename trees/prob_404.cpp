/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int result;
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root -> left && is_leaf(root -> left))
            result += root -> left -> val;

        if(root -> left)
            sumOfLeftLeaves(root -> left);

        if(root -> right)
            sumOfLeftLeaves(root -> right);

        return result;
    }

    bool is_leaf(TreeNode* root) {
        return !root -> left && !root -> right;
    }
};

//man goddamn my code has started to look cleaner now. Yes I know this is an easy problem but baby steps lol