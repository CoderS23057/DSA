class Solution {
public:
void fun(vector<int> nums,vector<int> output,int index,vector<vector<int> >& ans){
        if(index>=nums.size()){
            ans.push_back(output);
            return;
        }
        fun(nums,output,index+1,ans);
        output.push_back(nums[index]);
        fun(nums,output,index+1,ans);
        output.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > ans;
        vector<int> output;
        int index=0;
        fun(nums,output,index,ans);
        return ans;

    }
};