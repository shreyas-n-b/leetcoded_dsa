class Solution {
    int dp[2][101][101];
    int solveForAlice(int person, int i, int M, vector<int>& piles){
        int n=piles.size();
        if(i>=n)return 0;
        if(dp[person][i][M]!=-1)return dp[person][i][M];
        int stones = 0;
        int result = (person == 1)?-1:INT_MAX;
        for(int x=1; x<=min(2*M,n-i); x++){
            stones += piles[i+x-1];
            if(person == 1){
                result = max(result, stones+solveForAlice(0,i+x,max(M,x),piles));
            }
            else{
                result = min(result, solveForAlice(1,i+x,max(M,x),piles));
            }
        }    
        return dp[person][i][M]=result;    
    }
public:
    int stoneGameII(vector<int>& piles) {
        memset(dp,-1,sizeof(dp));
        return solveForAlice(1,0,1,piles);        
    }
};