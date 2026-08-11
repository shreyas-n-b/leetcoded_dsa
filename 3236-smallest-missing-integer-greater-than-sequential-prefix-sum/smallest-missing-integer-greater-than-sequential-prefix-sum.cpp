class Solution {
public:
    int missingInteger(vector<int>& nums) {
        const int maxnum=50;
        int n=nums.size();
        int sum=nums[0];
        int i;
        for(i=1; i<n; i++){
            if(nums[i] != nums[i-1]+1){
                break;
            }
            sum += nums[i];
        }
        if(sum > maxnum)return sum;
        vector<bool> freq(maxnum-sum+1,false);
        i=0;
        while(i<n){
            if(nums[i]>=sum){
                freq[nums[i]-sum]=true;
            }
            i++;
        }
        for(int j=0; j<freq.size(); j++){
            if(freq[j] == false){
                return sum+j;
            }
        }
        return maxnum+1;        
    }
};