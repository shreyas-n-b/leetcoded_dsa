class Solution {
    int divideNums(vector<int>& nums, long long limit){
        int n=nums.size();
        int cnt=0;
        long long sum = 0;
        for(int i=0; i<n; i++){
            if(sum + nums[i] > limit){
                cnt++;
                sum = 0;
            }
            sum += nums[i];
        }
        if(sum > 0)cnt++;
        return cnt;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        long long sum=accumulate(nums.begin(), nums.end(), 0);
        int maxi=*max_element(nums.begin(), nums.end());
        long long low=maxi;
        long long high=sum;
        int ans=0;
        while(low<=high){
            long long mid=low+(high-low)/2;
            int divisionsCnt=divideNums(nums,mid);
            if(divisionsCnt <= k){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};