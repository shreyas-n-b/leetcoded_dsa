class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        if(n<2)return 0;
        sort(nums.begin(),nums.end());
        int median;
        if(n%2==0){
            int a=n/2;
            int b=a-1;
            median=(nums[a]+nums[b])/2;
        }else{
            int a=n/2;
            median=nums[a];
        }
        int targ=median;
        int ans=0;
        for(int i=0; i<n; i++){
            ans += abs(nums[i]-targ);
        }
        return ans;        
    }
};