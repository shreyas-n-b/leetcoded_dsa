class Solution {
private:
    int pOneScore=0;
    int pTwoScore=0;
    bool f(bool turn, int l, int r, vector<int>& nums){
        if(l == r){
            if(turn){
                pOneScore += nums[l];
                bool temp=(pOneScore >= pTwoScore);
                pOneScore -= nums[l];
                return temp;
            }else{
                pTwoScore += nums[l];
                bool temp=(pOneScore < pTwoScore);
                pTwoScore -= nums[l];
                return !temp;
            }
        }
        bool leftpick;
        bool rightpick;
        if(turn){
            pOneScore += nums[l];
            leftpick=f(!turn, l+1, r, nums);
            pOneScore -= nums[l];

            pOneScore += nums[r];
            rightpick=f(!turn, l, r-1, nums);
            pOneScore -= nums[r];
        }else{
            pTwoScore += nums[l];
            leftpick=f(!turn, l+1, r, nums);
            pTwoScore -= nums[l];

            pTwoScore += nums[r];
            rightpick=f(!turn, l, r-1, nums);
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
        return f(true,0,nums.size()-1,nums);        
    }
};