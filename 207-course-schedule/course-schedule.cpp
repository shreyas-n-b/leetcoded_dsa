class Solution {
    bool dfs(int node, vector<int>& vis, vector<vector<int>>& adj){
        if(vis[node]==1)return false;
        if(vis[node]==2)return true;
        vis[node]=1;
        for(auto it:adj[node]){
            if(!dfs(it,vis,adj))return false;
        }
        vis[node]=2;
        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> vis(numCourses,0);
        vector<vector<int>> adj(numCourses,vector<int>());
        for(auto course: prerequisites){
            adj[course[1]].push_back(course[0]);
        }
        for(int i=0; i<numCourses; i++){
            if(vis[i]==0 && dfs(i,vis,adj)==false){
                return false;
            }
        }
        return true;        
    }
};