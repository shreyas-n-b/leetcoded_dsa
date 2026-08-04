class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n=nums.size();
        if(n==0)return vector<int>();
        int end=*max_element(nums.begin(), nums.end());
        int start=*min_element(nums.begin(),nums.end());
        vector<int> freq(end-start+1, 0);
        for(int i=0; i<n; i++){
            freq[nums[i]-start]++;
        }

        vector<int> ans;
        for(int i=0; i<end-start+1; i++){
            if(freq[i]==0){
                ans.push_back(start+i);
            }
        }

        return ans;
        
    }
};