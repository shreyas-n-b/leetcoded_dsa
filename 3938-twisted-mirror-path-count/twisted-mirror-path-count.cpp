class Solution {
    const int MOD=(int)1e9 + 7;
    void traverseMirrors(int& r, int& c, int dir, vector<vector<int>>& grid){
        int m=grid.size();
        int n=grid[0].size();
        if(r>0 && r<m && c>0 && c<n){
            if(grid[r][c]==0)return;
        }
        //if moved right then move down and call again
        if(dir==0){
            //if down exists move there else return i set to -1 and j set to -1;
            if(r+1<m){
                r++;
                if(grid[r][c]==1){
                    traverseMirrors(r,c,1,grid);
                }
            }else{
                r=-1;
                c=-1;
            }
        }else{
            //if right exists then move there else set r to -1 and c to -1 and return
            if(c+1<n){
                c++;
                if(grid[r][c]==1){
                    traverseMirrors(r,c,0,grid);
                }
            }else{
                r=-1;
                c=-1;
            }
        }
        return;
    }
    int f(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp){
        int m=grid.size();
        int n=grid[0].size();
        //base cases 
        if(i==m-1 && j==n-1)return 1;
        if(dp[i][j]!=-1)return dp[i][j];
        int right=0;
        int down=0;
        //go right
        if(j+1<n){
            int newj=j+1;
            int newi=i;
            if(grid[newi][newj]==1){
                traverseMirrors(newi,newj,0,grid);
                if(newi==-1 && newj==-1)right=0;
                else right=f(newi,newj,grid,dp);
            }else{
                right=f(newi,newj,grid,dp);
            }
        }
        //go down
        if(i+1<m){
            int newi=i+1;
            int newj=j;
            if(grid[newi][newj]==1){
                traverseMirrors(newi,newj,1,grid);
                if(newi==-1 && newj==-1)down=0;
                else down=f(newi,newj,grid,dp);
            }else{
                down=f(newi,newj,grid,dp);
            }
        }
        return dp[i][j]=((right%MOD)+(down%MOD))%MOD;
    }
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return f(0,0,grid,dp)%MOD;      
    }
};