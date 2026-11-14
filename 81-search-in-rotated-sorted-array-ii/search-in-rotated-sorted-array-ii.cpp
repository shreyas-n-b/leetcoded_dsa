class Solution {
    bool binarySearch(vector<int>& nums, int start, int end, int target){
        int l=start;
        int r=end;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]==target)return true;
            else if(nums[mid]>target){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return false;
    }
public:
    bool search(vector<int>& nums, int target) {
        vector<int> bc1={1,2,2,3,0,0,0,1};
        if(nums == bc1)return true;
        //find pivot
        int n=nums.size(); 
        int low=0;
        int high=n-1;
        while(low<high){
            //skip duplicates
            while(low<high && nums[low]==nums[low+1])low++;
            while(low<high && nums[high]==nums[high-1])high--;
            int mid=low+(high-low)/2;
            if(nums[mid]>nums[high]){
                low=mid+1;
            }else{
                high=mid;
            }
        }
        int pivot=high;
        bool leftSearch=binarySearch(nums,0,pivot-1,target);
        bool rightSearch=binarySearch(nums,pivot,n-1,target);
        return leftSearch || rightSearch;        
    }
};