class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n=nums.size();
        if(n==0)return vector<int>();
        sort(nums.begin(),nums.end());
        int n1=nums[0];
        int n2=nums[n-1];
        vector<int> temp(n2-n1+1);
        vector<int> ans;
        iota(temp.begin(),temp.end(),n1);
        int j=0;
        for(int i=0; i<n; i++){
            while(j<(n2-n1+1) && nums[i] != temp[j]){
                ans.push_back(temp[j]);
                j++;
            }
            j++;
        }
        return ans;
    }
};