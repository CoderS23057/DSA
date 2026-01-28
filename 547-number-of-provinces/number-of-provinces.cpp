class Solution {
public:

    void dfs(int node, vector<bool>&visited, vector<vector<int>>&isConnected){
        visited[node] = 1;
         for (int j = 0; j < isConnected.size(); j++) {
            if (isConnected[node][j] == 1 && !visited[j]) {
                dfs(j, visited, isConnected);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int count =0;
        vector<bool> visited(n,0);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                count++;
                dfs(i,visited,isConnected);
            }
        }
        return count;
    }
};