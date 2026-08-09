class Solution {
private:
    int solve(int i, int j, vector<int>& nums){
        if(i>j)return 0;
        if(i==j)return nums[i];
        int takei=nums[i]+min(solve(i+2,j,nums),solve(i+1,j-1,nums));
        int takej=nums[j]+min(solve(i+1,j-1,nums),solve(i,j-2,nums));
        return max(takei,takej);
    }
public:
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        int totalScore=accumulate(nums.begin(),nums.end(),0);
        int player1score=solve(0,n-1,nums);
        int player2score=totalScore-player1score;
        return player1score >= player2score;        
    }
};