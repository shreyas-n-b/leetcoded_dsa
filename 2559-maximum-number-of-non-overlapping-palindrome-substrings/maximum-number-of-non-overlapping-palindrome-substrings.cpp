class Solution {
    bool isPalindrome(string& s, int start, int end){
        for(int i=0; i<(end-start+1)/2; i++){
            if(s[start+i]!=s[end-i])return false;
        }
        return true;
    }
    int solve(string& s, int k, int i, int j, vector<vector<int>>& dp){
        int n=s.length();
        if(j>=n || i>=n)return 0;
        if(dp[i][j] != -1)return dp[i][j];
        int take=-1;
        if(isPalindrome(s,i,j)){
            take=1+solve(s,k,j+1,j+k,dp);
        }
        int grow=solve(s,k,i,j+1,dp);
        int slide=solve(s,k,i+1,j+1,dp);
        return dp[i][j]=max(take,max(grow,slide));
    }
public:
    int maxPalindromes(string s, int k) {
        int n=s.length();
        if(n<k)return 0;
        if(k==1)return n;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(s,k,0,k-1,dp);       
    }
};