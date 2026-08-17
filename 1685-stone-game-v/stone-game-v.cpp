class Solution {
    int solve(int l, int r, vector<int>& nums, vector<vector<int>>& dp) {
    if (l == r)
        return 0;

    if(dp[l][r] != -1)return dp[l][r];

    int totalSum = 0;
    for (int i = l; i <= r; i++)
        totalSum += nums[i];

    int sum = 0;
    int ans = 0;

    for (int i = l; i < r; i++) {
        sum += nums[i];
        int remSum = totalSum - sum;

        if (sum < remSum) {
            // Alice keeps left part
            ans = max(ans, sum + solve(l, i, nums, dp));
        }
        else if (sum > remSum) {
            // Alice keeps right part
            ans = max(ans, remSum + solve(i + 1, r, nums, dp));
        }
        else {
            // Alice can keep either part
            ans = max({
                ans,
                sum + solve(l, i, nums, dp),
                remSum + solve(i + 1, r, nums, dp)
            });
        }
    }

    return dp[l][r]=ans;
}
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n=stoneValue.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(0,n-1,stoneValue,dp);        
    }
};