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
    int maxLevelSum(TreeNode* root) {
        if(root == nullptr) return 0;

        queue<TreeNode*>q;
        vector<int>level;
        q.push(root);
        int ans = INT_MIN;
        while(!q.empty()){
            int s = q.size();
            int sum = 0;
            for(int i=0;i<s;i++){
                TreeNode* temp = q.front();
                q.pop();
                sum+=temp->val;
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            level.push_back(sum);
            ans = max(ans,sum);
        }
        int a;
        for(int i=0;i<level.size();i++){
            if(level[i] == ans){
                a = i;
                break;
            }
        }
        return a+1;
        
    }
};