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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL){
            return ans;
        }
        queue<TreeNode*>nodeq;
        nodeq.push(root);
        bool lefttoright=true;

        while(!nodeq.empty()){
            int size=nodeq.size();
            vector<int>rows(size);

            for(int i=0;i<size;i++){
                TreeNode* node=nodeq.front();
                nodeq.pop();

                int index = (lefttoright) ? i : (size-i-1);
                rows[index]=node->val;
                if(node->left){
                    nodeq.push(node->left);
                }
                if(node->right){
                    nodeq.push(node->right);
                }
            }
            lefttoright=!lefttoright;
            ans.push_back(rows);
        }
        return ans;
    }
};