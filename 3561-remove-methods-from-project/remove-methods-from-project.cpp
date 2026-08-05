class Solution {
private:
    void findBugs(int node, vector<vector<int>>& adj, unordered_set<int>& buggyMethods){
        buggyMethods.insert(node);
        for(int v: adj[node]){
            if(buggyMethods.count(v)==0){
                findBugs(v,adj,buggyMethods);
            }
        }
    }

    bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis, 
    unordered_set<int>& buggyMethods){
        vis[node]=1;
        if(buggyMethods.count(node)==1){
            return true;
        }
        for(int v: adj[node]){
            if(!vis[v]){
                if(dfs(v,adj,vis,buggyMethods)){
                    return true;
                }
            }
        }
        return false;
    }
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        unordered_set<int> buggyMethods;
        vector<vector<int>> adj(n,vector<int>());
        for(vector<int> invocation: invocations){
            adj[invocation[0]].push_back(invocation[1]);
        }
        vector<int> vis(n,0);
        findBugs(k,adj,buggyMethods);
        bool flag=false;

        
        for(int i=0; i<n; i++){
            if(buggyMethods.count(i)==1)continue;
            if(!vis[i]){
                if(dfs(i,adj,vis,buggyMethods)){
                    flag=true;
                    break;
                }
            }
        }
        vector<int> ans;
        if(flag){
            for(int i=0; i<n; i++){
                ans.push_back(i);
            }
        }else{
            for(int i=0; i<n; i++){
                if(buggyMethods.count(i)==1)continue;
                ans.push_back(i);
            }
        }

        return ans;
        
    }
};