class Solution {
private:
    int pOneScore=0;
    int pTwoScore=0;
    bool f(bool turn, int l, int r, vector<int>& nums, vector<vector<vector<int>>>& dp){
        if(l == r){
            if(turn){
                pOneScore += nums[l];
                bool temp=(pOneScore >= pTwoScore);
                pOneScore -= nums[l];
                return (bool)(dp[turn][l][l]=temp);
            }else{
                pTwoScore += nums[l];
                bool temp=(pOneScore < pTwoScore);
                pTwoScore -= nums[l];
                return (bool)(dp[turn][l][l]=!temp);
            }
        }
        if(dp[turn][l][r]!=-1)return (bool)dp[turn][l][r];
        bool leftpick;
        bool rightpick;
        if(turn){
            pOneScore += nums[l];
            leftpick=f(!turn, l+1, r, nums, dp);
            pOneScore -= nums[l];

            pOneScore += nums[r];
            rightpick=f(!turn, l, r-1, nums, dp);
            pOneScore -= nums[r];
        }else{
            pTwoScore += nums[l];
            leftpick=f(!turn, l+1, r, nums, dp);
            pTwoScore -= nums[l];

            pTwoScore += nums[r];
            rightpick=f(!turn, l, r-1, nums, dp);
            pTwoScore -= nums[r];
        }

        if(turn){
            return (leftpick || rightpick);
        }else{
            return (leftpick && rightpick);
        }
    }
public:
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        vector<vector<vector<int>>> dp(2,vector<vector<int>>(n,vector<int>(n,-1)));
        return f(true,0,nums.size()-1,nums,dp);        
    }
};