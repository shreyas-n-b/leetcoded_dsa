class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        if(n<2)return nums[0];
        if(nums[1]!=nums[0])return nums[0];
        if(nums[n-1]!=nums[n-2])return nums[n-1];
        int high=n-2;
        int low=1;
        while(low<=high){
            int i=low+(high-low)/2;
            if(nums[i+1]!=nums[i] && nums[i-1]!=nums[i]){
                return nums[i];
            }
            if(i%2==0){
                if(nums[i-1] == nums[i]){
                    high=i-1;
                }
                else{
                    low=i+1;
                }
            }else{
                if(nums[i+1] == nums[i]){
                    high=i-1;
                }
                else{
                    low=i+1;
                }
            }
        }
        return -1;        
    }
};