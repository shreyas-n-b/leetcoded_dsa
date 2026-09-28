class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> hm;
        int n=nums.size();
        for(int i=0; i<n; i++)hm[nums[i]]++;
        vector<pair<int,int>> vec(hm.begin(), hm.end());
        sort(vec.begin(), vec.end(), [](const pair<int,int>& a, 
        const pair<int,int>& b){
            if(a.second==b.second)return a.first>b.first;
            return a.second<b.second;
        });
        vector<int> ans;
        for(int i=0; i<vec.size(); i++){
            int cnt=vec[i].second;
            while(cnt>0){
                ans.push_back(vec[i].first);
                cnt--;
            }
        }
        return ans;        
    }
};