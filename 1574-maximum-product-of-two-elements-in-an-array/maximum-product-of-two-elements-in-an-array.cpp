class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int maxi=0;
        int ind=-1;
        for(int i=0; i<n; i++){
            if(nums[i]>maxi){
                maxi=nums[i];
                ind=i;
            }
        }
        int a=maxi;
        maxi=0;
        for(int i=0; i<n; i++){
            if(i!=ind && nums[i]>maxi){
                maxi=nums[i];
            }
        }
        return (a-1)*(maxi-1);        
    }
};