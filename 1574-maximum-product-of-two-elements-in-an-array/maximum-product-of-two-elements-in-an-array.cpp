class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int maxi=0;
        int ind=-1;
        for(int i=0; i<n; i++){
            if(nums[i]>1 && nums[i]>maxi){
                maxi=nums[i];
                ind=i;
            }
        }
        if(maxi==0)return 0;
        int a=maxi;
        maxi=0;
        for(int i=0; i<n; i++){
            if(i==ind)continue;
            if(nums[i]>1 && nums[i]>maxi){
                maxi=nums[i];
            }
        }
        return (a-1)*(maxi-1);        
    }
};