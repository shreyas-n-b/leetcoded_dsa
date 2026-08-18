class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n=stoneValue.size();
        vector<int>& nums=stoneValue;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int i=0; i<n; i++){
            dp[i][i]=0;
        }
        for (int len = 2; len <= n; len++) {

            for (int l = 0; l + len - 1 < n; l++) {

                int r = l + len - 1;

                int totalSum = 0;
    for (int i = l; i <= r; i++)
        totalSum += nums[i];
    
    int sum = 0;
    int ans = 0;

    for (int i = l; i < r; i++) {
        sum += nums[i];
        int remSum = totalSum - sum;

        if(sum < remSum){
            ans = max(ans, sum+dp[l][i]);
        }
        else if(sum > remSum){
            ans = max(ans, remSum+dp[i+1][r]);
        }
        else{
            ans = max({ans,sum+dp[l][i],remSum+dp[i+1][r]});
        }
    }
    dp[l][r]=ans;
}
        }

return dp[0][n-1];
        
    }
};
