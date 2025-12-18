class Solution {
public:
    void fun(vector<int> nums,vector<int> &temp,int index,vector<vector<int> >& ans, int target, int sum){
        if(sum == target){
            ans.push_back(temp);
            return;
        }
        if (sum > target || index >= nums.size()) {
            return;
        }
        temp.push_back(nums[index]);
        fun(nums,temp,index,ans, target, sum+nums[index]);
        temp.pop_back();
        fun(nums,temp,index+1,ans, target,sum);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int> > ans;
        vector<int> temp;
        int sum = 0;
        fun(nums,temp,0,ans,target, sum);
        return ans;
    }
};