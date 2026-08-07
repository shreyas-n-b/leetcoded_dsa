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
    int f(TreeNode* node, int& maxi, int& maxnode){
        if(node == nullptr)return 0;
        int leftsum=max(0,f(node->left,maxi,maxnode));
        int rightsum=max(0,f(node->right,maxi,maxnode));
        maxi=max(maxi,(node->val+leftsum+rightsum));
        maxnode=max(maxnode,node->val);
        return node->val + max(leftsum,rightsum);
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxi=0;
        int maxnode=-1e5;
        f(root,maxi,maxnode);
        return (maxnode<0)?maxnode:maxi;
        
    }
};