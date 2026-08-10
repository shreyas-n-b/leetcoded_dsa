class Solution {
public:
    bool winnerSquareGame(int n) { 
        vector<vector<bool>> dp(2,vector<bool>(n+1));
        dp[0][0]=true;
        dp[1][0]=false;
        for(int i=1; i<=n; i++){ 
            //starting
            bool result = false;
            for(int j=1; j*j<=i; j++){
                result = result || dp[0][i-j*j];
            }
            dp[1][i]=result;
            result=true;
            for(int j=1; j*j<=i; j++){
                result = result && dp[1][i-j*j];
            }
            dp[0][i]=result;
            //ending
        }
        return dp[1][n];      
    }
};