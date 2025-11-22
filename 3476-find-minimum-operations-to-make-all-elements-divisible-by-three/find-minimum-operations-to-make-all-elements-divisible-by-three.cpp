class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        int count=0;
        int r;
        for(int x:nums){
            r = x%3;
            if(r==0 || x ==0) continue;
            else{
                count++;
            }
        }
        return count;
    }
};