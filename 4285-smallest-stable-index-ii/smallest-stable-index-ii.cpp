class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> minArr(n);
        int mini=INT_MAX;
        for(int j=n-1; j>=0; j--){
            mini=min(mini,nums[j]);
            minArr[j]=mini;
        }
        int maxi=INT_MIN;
        int ist_score;
        for(int i=0; i<n; i++){
            maxi=max(maxi,nums[i]);
            ist_score=maxi-minArr[i];
            if(ist_score<=k)return i;
        }
        return -1;        
    }
};