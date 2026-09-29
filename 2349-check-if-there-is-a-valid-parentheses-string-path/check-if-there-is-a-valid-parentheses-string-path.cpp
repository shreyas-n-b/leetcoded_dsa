class Solution {
    bool f(int r, int c, int& brackets, vector<vector<char>>& grid,vector<vector<vector<int>>>& dp){
        int m=grid.size();
        int n=grid[0].size();
        if(r>=m || c>=n)return false;
        brackets += (grid[r][c]=='(')?1:-1;
        if(brackets > (m+n-2)-(r+c)){
            brackets -= (grid[r][c]=='(')?1:-1;
            return false;
        }
        if(brackets < 0){
            brackets -= (grid[r][c]=='(')?1:-1;
            return false;
        }
        if(r==m-1 && c==n-1){
            bool check=brackets==0;
            brackets -= (grid[r][c]=='(')?1:-1;
            return check;
        }
        if(dp[r][c][brackets]!=-1){
            bool ans=dp[r][c][brackets];
            brackets -= (grid[r][c]=='(')?1:-1;
            return ans;
        };
        bool right=f(r,c+1,brackets,grid,dp);
        bool down=f(r+1,c,brackets,grid,dp);
        bool ans=right || down;
        dp[r][c][brackets]=ans;
        brackets -= (grid[r][c]=='(')?1:-1;
        return ans;
    }
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int brackets=0;
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>((m+n)/2+1,-1)));
        return f(0,0,brackets,grid,dp);        
    }
};