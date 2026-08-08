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
    unordered_map<TreeNode*,int> mpp;
public:
    int height(TreeNode* root){
        if(root == nullptr)return 0;
        int leftheight=height(root->left);
        int rightheight=height(root->right);
        return mpp[root]=1+max(leftheight,rightheight);
    }
    bool helper(TreeNode* root) {
        if(root == nullptr){
            return true;
        }
        int leftfactor=(root->left==nullptr)?0:mpp[root->left];
        int rightfactor=(root->right==nullptr)?0:mpp[root->right];
        int balFactor=leftfactor-rightfactor;
        if(balFactor != 0 && balFactor != -1 && balFactor != 1)return false;
        return (helper(root->left) && helper(root->right));       
    }
    bool isBalanced(TreeNode* root){
        if(root == nullptr)return true;
        mpp[root]=max(height(root->left),height(root->right))+1;
        return helper(root);
    }
};