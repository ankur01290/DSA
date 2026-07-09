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
    int dfsheight(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int lft=dfsheight(root->left);
        if(lft==-1) return -1;
        int rht=dfsheight(root->right);
        if(rht==-1)return -1;
        if(abs(lft-rht)>1) return -1;
        return 1+ max(lft,rht);
    }
    bool isBalanced(TreeNode* root) {
        return dfsheight(root)!=-1;
    }
    
};