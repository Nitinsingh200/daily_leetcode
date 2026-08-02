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
 int galat =0;
 TreeNode*  prev = NULL;
     pair<TreeNode*, TreeNode*> g1 = {NULL, NULL};
    pair<TreeNode*, TreeNode*> g2 = {NULL, NULL};
  void  fun( TreeNode* root){
     if( root== NULL)
     return ;


     fun(root->left);
     
     if(prev == NULL){
     prev = root;

     }

     else{
        if( root->val <prev->val){
    if(galat  == 0){
            g1.first = prev;
            g1.second = root;
            galat++;


        }else{
            g2.first = prev;
            g2.second = root;
            galat++;

        }
        }
    
     prev  =root;

     }
     fun(root->right);

     
  }



    void recoverTree(TreeNode* root) {
        fun( root);

        if( galat == 1){
             swap( g1.first->val,g1.second->val);

        }else{
           swap( g1.first->val, g2.second->val);

        }
        
    }
};