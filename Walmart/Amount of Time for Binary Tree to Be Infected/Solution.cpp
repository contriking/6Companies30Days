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
    TreeNode* parentNode(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&parent,
    unordered_map<TreeNode*,bool>&visited,TreeNode* &startptr,int start){
        if(root==NULL){
            return startptr;
        }
        if(root->val==start){
            startptr=root;
        }
        if(root->left!=NULL){
            parent[root->left]=root;
            parentNode(root->left,parent,visited,startptr,start);
        }
        if(root->right!=NULL){
            parent[root->right]=root;
            parentNode(root->right,parent,visited,startptr,start);
        }
        visited[root]=false;
        return startptr;
    }

    int amountOfTime(TreeNode* root, int start) {
        if(root->left==NULL && root->right==NULL){
            return 0;
        }
        unordered_map<TreeNode*,TreeNode*>parent;
        unordered_map<TreeNode*,bool>visited;
        TreeNode* startNode=NULL;
        parent[root]=NULL;
        parentNode(root,parent,visited,startNode,start);
        int ans=0;
        queue<TreeNode*>q;
        q.push(startNode);
        visited[startNode]=true;
        while(!q.empty()){
            int n=q.size();
            bool change=false;
            for(int i=0;i<n;i++){
                TreeNode* front=q.front();
                q.pop();
                if(front->left && visited[front->left]==false){
                    q.push(front->left);
                    visited[front->left]=true;
                    change=true;
                }
                if(front->right && visited[front->right]==false){
                    q.push(front->right);
                    visited[front->right]=true;
                    change=true;
                }
                if(parent[front]!=NULL && visited[parent[front]]==false){
                    q.push(parent[front]);
                    visited[parent[front]]=true;
                    change=true;
                }
            }
            if(change==true){
                ans++;
            }
        }
        return ans;
    }
};