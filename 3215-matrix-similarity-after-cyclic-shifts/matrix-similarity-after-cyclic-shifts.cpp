class Solution {
public:
    void leftRotate(vector<int>& arr, int k) {
    int n = arr.size();
    if (n == 0) return;

    k = k % n;

    reverse(arr.begin(), arr.begin() + k);
    reverse(arr.begin() + k, arr.end());
    reverse(arr.begin(), arr.end());
}
void rightRotate(vector<int>& arr, int k) {
    int n = arr.size();
    if (n == 0) return;

    k = k % n;

    reverse(arr.begin(), arr.end());
    reverse(arr.begin(), arr.begin() + k);
    reverse(arr.begin() + k, arr.end());
}
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> temp = mat;
        if(m==0) return true;
        for(int i=0;i<m;i++){
            if(i%2==0){
                leftRotate(mat[i],k);
            }
            else{
                rightRotate(mat[i],k);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] != temp[i][j]){
                    return false;
                }
            }
        }
        return true;

    }
};