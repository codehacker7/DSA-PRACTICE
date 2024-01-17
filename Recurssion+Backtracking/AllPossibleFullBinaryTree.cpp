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
    vector<TreeNode*> helper(int n){
        if(n == 1){
            TreeNode * base = new TreeNode(0);
            vector<TreeNode*> vec;
            vec.push_back(base);
            return vec;
        }

        vector<TreeNode*> ans;
        for(int i=1;i<n;i+=2){
            vector<TreeNode*> leftside = helper(i);
            vector<TreeNode*> rightside = helper(n-i-1);


            for(TreeNode* l : leftside){
                for(TreeNode* r: rightside){
                    TreeNode* root = new TreeNode(0);
                    root->left = l;
                    root->right = r;
                    ans.push_back(root);
                }
            }
        }
        return ans;


    }

    vector<TreeNode*> allPossibleFBT(int n) {

        return helper(n);
    
        
    }
};