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
    void findPath(TreeNode* root, int targetSum,vector<vector<int>> &ans ,vector<int> &curPath){
        if (!root) return;
        curPath.push_back(root->val);
        targetSum -= root->val;

        if(!root->left && !root->right && targetSum == 0){
            ans.push_back(curPath);
        }
        findPath(root->left, targetSum, ans, curPath);
        findPath(root->right, targetSum, ans, curPath);

        curPath.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans ;
        vector<int> curPath ;
        findPath(root,targetSum,ans,curPath);
        return ans;
    }
};