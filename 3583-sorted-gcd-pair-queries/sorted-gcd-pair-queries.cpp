// class Solution {
//     private:
//     int findMax(vector<int>& v){
//         int maxi=v[0];
//         for(int i=1; i<v.size(); i++){
//             if(v[i]>maxi){
//                 maxi=v[i];
//             }
//         }
//         return maxi;
//     }
//     void countingSort(vector<int>& v){
//         int m=findMax(v);
//         vector<int> count(m+1,0);
//         vector<int> output(v.size(),-1);

//         for(int p: v){
//             count[p]++;
//         }

//         for(int i=1; i<m+1; i++){
//             count[i] += count[i-1];
//         }

//         for(int j=m; j>=0 && count[j]>0; j--){
//             output[count[j]-1]=j;
//         }
//         for(int j=output.size()-2; j>=0; j--){
//             if(output[j]==-1){
//                 output[j]=output[j+1];
//             }
//         }
//         v=move(output);
//         return;
//     }
// public:
//     vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
//         int n=nums.size();
//         vector<int> ans;
//         if(n==0)return ans;
//         vector<int> gcdPairs;
//         for(int i=0; i<n; i++){
//             for(int j=i+1; j<n; j++){
//                 gcdPairs.push_back(__gcd(nums[i],nums[j]));
//             }
//         }

//         countingSort(gcdPairs);
//         cout<<endl;
//         for(int e: gcdPairs){
//             cout<<e<<" ";
//         }
//         cout<<endl;
//         int m=gcdPairs.size();
//         for(int i=0; i<queries.size(); i++){
//             if(queries[i]<m){
//                 ans.push_back(gcdPairs[queries[i]]);
//             }
//         }

//         return ans;
        
//     }
// };
class Solution {
    using ll = long long;
public:
    vector<int> gcdValues(vector<int>& A, vector<long long>& queries) {
        int mx = ranges::max(A);
        vector<int> freq(mx + 1, 0);
        vector<ll> GCD(mx + 1, 0);
        
        for (auto& a : A) freq[a]++;
        
        for (int i = mx; i > 0; i--) {
            ll sm = 0, extra = 0;
            for (int j = i; j <= mx; j += i)
                sm += freq[j], extra += GCD[j];
            GCD[i] = sm * (sm - 1) / 2 - extra;
        }
        
        partial_sum(GCD.begin(), GCD.end(), GCD.begin());
        
        vector<int> res(queries.size());
        for (int i = 0; i < queries.size(); i++)
            res[i] = ranges::upper_bound(GCD, queries[i]) - GCD.begin();
            
        return res;
    }
};