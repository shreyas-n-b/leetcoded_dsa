// class Solution {
//     const long long MOD = 1e9 + 7;
//     long long nCr(long long n, long long r) {
//         __int128 res = 1;
//         for (long long i = 0; i < r; i++) {
//             res = res * (n - i) / (i + 1);
//         }
//         return (long long)(res % MOD);
//     }
// public:
//     int numberOfSets(int n, int k) {
//         long long ans=0;
//         for(int gaps=1; gaps<n-k; gaps++){
//             ans = (ans+nCr(n-1,gaps))%MOD;
//         }
//         long long forZero=nCr(n-2,k-1);
//         return (int)((ans+forZero)%MOD);        
//     }
// };
class Solution {
public:
    static const int MOD = 1e9 + 7;

    int numberOfSets(int n, int k) {
        vector<vector<long long>> dp(n, vector<long long>(k + 1));
        // 0 segments → exactly 1 way
        for(int i = 0; i < n; i++) dp[i][0] = 1;

        for(int j = 1; j <= k; j++){
            long long sum = 0;
            for(int i = 1; i < n; i++){
                // Add ways for j-1 segments
                sum = (sum + dp[i - 1][j - 1]) % MOD;
                // Don't use i OR end a segment at i
                dp[i][j] = (dp[i - 1][j] + sum) % MOD;
            }
        }

        return dp[n - 1][k];
    }
};