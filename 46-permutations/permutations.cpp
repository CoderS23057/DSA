class Solution {
public:
    void permutation(vector<int> &nums, vector<bool> &visited, vector<int> &temp, vector<vector<int> > &ans){
        if(temp.size()== nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(visited[i]==0){
                visited[i] = 1;
                temp.push_back(nums[i]);
                permutation(nums,visited,temp,ans);
                visited[i] = 0;
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visited(n,0);
        vector<vector<int> >ans;
        vector<int> temp;
        permutation(nums,visited,temp,ans);
        return ans;
    }
};