class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int n = nums.size();
        unordered_set<int>temp;
        for(int i=0;i<n;i++){
            temp.insert(nums[i]);
        }
        while( temp.count(original)){
            original *=2;
        }
        return original;
    }
};