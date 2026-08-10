class Solution {
    int dp[2][(int)1e5+1];
    bool solveForAlice(int turn, int stonesLeft){
        if(stonesLeft==0){
            if(turn == 1){
                return false;
            }else{
                return true;
            }
        }
        if(dp[turn][stonesLeft]!=-1)return dp[turn][stonesLeft];
        bool result = (turn == 1)?false:true;
        for(int i=1; i*i<=stonesLeft; i++){
            if(turn == 1){
                result = result || solveForAlice(!turn, stonesLeft-i*i);
            }else{
                result = result && solveForAlice(!turn, stonesLeft-i*i);
            }
        }
        return dp[turn][stonesLeft]=result;
    }
public:
    bool winnerSquareGame(int n) {
        memset(dp,-1,sizeof(dp));
        return solveForAlice(1,n);        
    }
};