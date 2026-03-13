class Solution {
public:
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n,-1);
        queue<int>q;
        for(int i=0;i<n;i++){
            if(color[i] == -1){
                q.push(i);
                color[i] = 0;  // coloring the node
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    //check neighbours 
                    for(int j=0;j<graph[node].size();j++){
                        if(color[graph[node][j]] == -1){   //if not assigned color then assign them
                            color[graph[node][j]] = (color[node]+1)%2;
                            q.push(graph[node][j]);
                        }
                        else{
                            if(color[node] == color[graph[node][j]]) return 0;
                        }
                    }
                }

            }
        }
        return -1;
    }
};