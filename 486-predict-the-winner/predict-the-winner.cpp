class Solution {
private:
    int dp[20][20];
    int solve(int i, int j, vector<int>& nums){
        if(i>j)return 0;
        if(i==j)return dp[i][j]=nums[i];
        if(dp[i][j]!=-1)return dp[i][j];
        int takei=nums[i]+min(solve(i+2,j,nums),solve(i+1,j-1,nums));
        int takej=nums[j]+min(solve(i+1,j-1,nums),solve(i,j-2,nums));
        return dp[i][j]=max(takei,takej);
    }
public:
    bool predictTheWinner(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int n=nums.size();
        int totalScore=accumulate(nums.begin(),nums.end(),0);
        int player1score=solve(0,n-1,nums);
        int player2score=totalScore-player1score;
        return player1score >= player2score;        
    }
};