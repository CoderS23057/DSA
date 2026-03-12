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
TreeNode* build(int &ind, vector<int>& p, vector<int>& in, int l, int r){
        if(l>r) return nullptr;
        TreeNode* root = new TreeNode(p[ind--]);
        int temp;
        for(int i=l; i<r; i++){
            if(in[i] == root->val){
                temp = i;
                break;
            }
        }
        root->right = build(ind,p,in,temp+1,r);
        root->left = build(ind,p,in,l,temp-1);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        TreeNode* root = NULL;
        int i =n-1;
        root = build(i,postorder,inorder, 0,n-1);
        return root;
    }
};