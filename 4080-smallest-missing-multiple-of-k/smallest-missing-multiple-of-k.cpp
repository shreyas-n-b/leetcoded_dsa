class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n=nums.size();
        int result=k*(n+1);
        unordered_set<int> hs;
        for(int num: nums){
            hs.insert(num);
        }
        for(int i=1; i<=n; i++){
            int target=k*i;
            if(hs.count(target)==0){
                return result=target;
            }
        }
        return result;        
    }
};