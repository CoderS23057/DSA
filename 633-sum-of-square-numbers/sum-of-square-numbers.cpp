class Solution {
public:
    bool judgeSquareSum(int c) {
        long long  i =0, j = sqrt(c);
        long long sum;
        while(i<=j){
            sum = i*i + j*j;
            if(sum == c){
                return true;
            }
            else if(sum<c){
                i++;
            }
            else{
                j--;
            }
        }
        return false;
    }
};