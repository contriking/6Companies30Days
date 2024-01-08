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

class Node{
    public:
    int mini;
    int maxi;
    int sum;
    bool isBST;
};

class Solution {
public:
    Node maxSumBST(TreeNode* root,int &ans){
        if(root==NULL){
            return {INT_MAX,INT_MIN,0,true};
        }
        Node left=maxSumBST(root->left,ans);
        Node right=maxSumBST(root->right,ans);

        if(left.isBST && right.isBST && left.maxi<root->val && root->val < right.mini){
            int sum=root->val+left.sum+right.sum;
            ans=max(ans,sum);
            return {min(left.mini,root->val),max(right.maxi,root->val),sum,true};
        }
        else{
            return {0,0,0,false};
        }

    }

    int maxSumBST(TreeNode* root) {
        int ans=0;
        maxSumBST(root,ans);
        return ans;
    }
};