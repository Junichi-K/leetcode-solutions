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
    unordered_map<TreeNode *, int> map;
public:
    int rob(TreeNode* root) {
        return helper_function(root, false);
    }

    int helper_function(TreeNode *root, bool before_looted) {
        if(!root)   //if root doesn't exist we ofcourse can't rob it, so we return a rob value of 0
            return 0;

        if(before_looted)   //since the house before (or above) in the tree was looted, we have no choice but to skip the current house so we call the function both 
                            //children and all the result together
            return helper_function(root -> left, false) + helper_function(root -> right, false);

        else {  //the prevoius house was not robbed, this leaves us with two decisions, we can rob the current house or we skip it as well
            if(map.find(root) != map.end()) //if max rob value for a root (where we consider the root) has already been computed in dp, we return that
                return map[root];

            map[root] = max((root -> val + helper_function(root -> left, true) + helper_function(root -> right, true)), (helper_function(root -> left, false) + 
            helper_function(root -> right, false)));    //assigning the value to the dp, first term is when we loot the current house, the other term is when we skip it
            
            return map[root];
        }

        return 0;   //control never reaches here, just to avoid errors
    }
};

//alright so I am pretty satisfied with my code. First didn't realize i needed dp, then implemented it using map and it works. Not the best runtime, did found better
//solutions which make use of pair<int, int> where first is when we consider and second is when we don't. My code is kinda similar too but of course the other is better.
//Since I was satisfied with my own code, I will not bother changing it to the better one which I usually do when I am unsatisfied