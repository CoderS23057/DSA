class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minIndex = 0, maxIndex = 0;

        // find indices of min and max elements
        for (int i = 0; i < n; i++) {
            if (nums[i] < nums[minIndex]) minIndex = i;
            if (nums[i] > nums[maxIndex]) maxIndex = i;
        }

        // option 1: remove both from front
        int front = max(minIndex, maxIndex) + 1;

        // option 2: remove both from back
        int back = n - min(minIndex, maxIndex);

        // option 3a: remove min from front, max from back
        int mix1 = (minIndex + 1) + (n - maxIndex);

        // option 3b: remove max from front, min from back
        int mix2 = (maxIndex + 1) + (n - minIndex);

        return min({front, back, mix1, mix2});
    }
};