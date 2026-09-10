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
    int findAverage(TreeNode* root){
        int avg=0;
        int cnt=0;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* node=st.top();
            st.pop();
            avg += node->val;
            cnt++;
            if(node->right)st.push(node->right);
            if(node->left)st.push(node->left);
        }
        return (int)(avg/cnt);
    }
public:
    int averageOfSubtree(TreeNode* root) {
        if(!root)return 0;
        int ans=0;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* node=st.top();
            st.pop();
            int nodeAverage=findAverage(node);
            if(node->val == nodeAverage)ans++;
            if(node->right)st.push(node->right);
            if(node->left)st.push(node->left);
        }
        return ans;        
    }
};