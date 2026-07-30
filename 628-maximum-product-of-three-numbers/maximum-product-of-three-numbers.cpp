/*class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        int product;
        if(nums[n-1]<0){
            product=nums[n-1]*nums[n-2]*nums[n-3];
        }else if(nums[0]<0 && nums[1]>0){
            product=nums[n-1]*nums[n-2]*nums[n-3];
        }else if(nums[1]<0){
            int p1=nums[0]*nums[1]*nums[n-1];
            int p2=nums[n-1]*nums[n-2]*nums[n-3];
            product=max(p1,p2);
        }else{
            product=nums[n-1]*nums[n-2]*nums[n-3];
        }
        return product;        
    }
};*/
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        int product;
        if(nums[1]<0){
            int p1=nums[0]*nums[1]*nums[n-1];
            int p2=nums[n-1]*nums[n-2]*nums[n-3];
            product=max(p1,p2);
        }else{
            product=nums[n-1]*nums[n-2]*nums[n-3];
        }
        return product;        
    }
};