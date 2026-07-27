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
class Nodevalue{
    public:
        int minNode, maxNode, maxSize;
        Nodevalue(int minNode,int maxNode,int maxSize){
            this->maxNode=maxNode;
            this->minNode=minNode;
            this->maxSize=maxSize;
        }
};
class Solution {
public:
    Nodevalue largestBST(TreeNode* root){
        if(!root){
            return Nodevalue(INT_MAX,INT_MIN,0);
        }

        auto left=largestBST(root->left);
        auto right=largestBST(root->right);

        if(left.maxNode < root->val && root->val < right.minNode){
            sum=max(sum,root->val + left.maxSize+right.maxSize);
            return Nodevalue(min(root->val,left.minNode),max(root->val,right.maxNode),left.maxSize+right.maxSize + root->val);
        }
        return Nodevalue(INT_MIN,INT_MAX , max(left.maxSize,right.maxSize));
    }
    int sum=0;
    int maxSumBST(TreeNode* root) {

        largestBST(root);
        return sum>0 ? sum:0;
    }
};