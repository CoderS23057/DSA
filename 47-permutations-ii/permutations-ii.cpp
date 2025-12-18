class Solution {
public:
    void permute(vector<int> &nums, int ind, vector<vector<int> > &ans){
        if(ind == nums.size()){
            ans.push_back(nums);
            return;
        }
        unordered_set<int> used; // used to track duplicates 
        for(int i=ind;i<nums.size();i++){
            if(used.count(nums[i])) continue;
            used.insert(nums[i]);
            swap(nums[ind], nums[i]);
            permute(nums,ind+1,ans);
            swap(nums[ind], nums[i]); // backtrack 
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>temp;
        vector<vector<int> >ans;
        permute(nums,0,ans);
        return ans;
    }
};