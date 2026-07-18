class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mini=nums[0];
        int maxi=nums[0];
        for(int n: nums){
            if(n<mini){
                mini=n;
            }
            if(n>maxi){
                maxi=n;
            }
        }
        return __gcd(mini,maxi);        
    }
};