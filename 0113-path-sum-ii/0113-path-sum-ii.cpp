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
vector<vector<int>>ans;
void solve(TreeNode* root, int targetSum,int sum,   vector<int>&path){
    if(root== NULL)
    return;

    sum +=root->val;
      path.push_back(root->val);
    if(root->left== NULL && root->right== NULL){
        if(sum == targetSum){
            ans.push_back(path);

        }
        path.pop_back();
        return;

    }

        solve(root->left, targetSum, sum, path);
        solve(root->right, targetSum, sum, path);

        path.pop_back(); 


}
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>path;
        solve(root,targetSum,0,path);
        return ans;


        
    }
};