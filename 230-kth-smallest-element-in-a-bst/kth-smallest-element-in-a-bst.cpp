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
public:
    void rin(TreeNode* node,vector<int>&ans){
        if(node==NULL){
            return;
        }
        rin(node->left,ans);
        ans.push_back(node->val);
        rin(node->right,ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        
        vector<int>ans;
        rin(root,ans);
        return ans[k-1];
    }
};