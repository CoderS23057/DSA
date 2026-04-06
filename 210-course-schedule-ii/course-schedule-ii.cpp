class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses];
        int n = prerequisites.size();
        vector<int>indeg(numCourses,0);
        for(int i=0;i<n;i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indeg[prerequisites[i][0]]++;
        }

        queue<int>q;
        //indegree calculation
        for(int i=0;i<numCourses;i++){
            if(!indeg[i]){
                q.push(i);
            }
        }
        vector<int>ans;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            //look at the neighbour
            for(auto it : adj[node]){
                indeg[it]--;
                if(!indeg[it]){
                    q.push(it);
                }
            }
        }
        vector<int>temp;
        return ans.size() == numCourses ? ans:temp;
    }
};