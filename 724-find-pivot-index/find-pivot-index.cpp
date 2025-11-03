class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int s = nums.size();
        int sum = 0;
        int Tsum = accumulate(nums.begin(),nums.end(),0);
        for(int i=0;i<s;i++){
            sum += nums[i];
            if(sum -nums[i] == Tsum -sum){
                return i;
            }
        }
        return -1;
    }
};