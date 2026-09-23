class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int sum=0;
        int totalSum=0;
        for(int ind=0; ind<n; ind++)totalSum += nums[ind];
        int targetSum=totalSum-x;
        if(targetSum == 0)return n;
        int maxlen=-1;
        int i=0;
        for(int j=0; j<n; j++){
            sum += nums[j];
            while(i<j && sum>targetSum){
                sum -= nums[i];
                i++;
            }
            if(sum==targetSum){
                maxlen=max(maxlen,j-i+1);
            }
        }
        return (maxlen==-1)?maxlen:n-maxlen;
    }
};