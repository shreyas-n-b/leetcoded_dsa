class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n=nums.size();
        //edge cases
        if(n<3)return 0; 
        sort(nums.begin(), nums.end());
        return min(min(nums[n-2]-nums[1],nums[n-1]-nums[2]),(nums[n-3]-nums[0]));        
    }
};