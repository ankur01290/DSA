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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()!=postorder.size()){
            return NULL;
        }
        map<int,int>mpp;
        for(int i=0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }
        TreeNode* root=Buildtree(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,mpp);
        return root;
    }
    TreeNode* Buildtree(vector<int>& inorder,int inStart,int inEnd,vector<int>& postorder,int postStart,int postEnd,map<int,int>& mpp){
        if(inStart>inEnd || postStart>postEnd){
            return NULL;
        }
        TreeNode* root=new TreeNode(postorder[postEnd]);
        int inRoot=mpp[postorder[postEnd]];
        int inleft=inRoot-inStart;
        root->left=Buildtree(inorder,inStart,inRoot-1,postorder,postStart,postStart+inleft-1,mpp);
        root->right=Buildtree(inorder,inRoot+1,inEnd,postorder,postStart+inleft,postEnd-1,mpp);
        return root;

    }
};