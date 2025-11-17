class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i] ==1){
                ans.push_back(i);
            }
        }
        int m = ans.size();
        for(int i=0;i<m-1;i++){
            if(ans[i+1]-ans[i]-1 < k){
                return false;
            }
        }
        return true;
    }
};