// class Solution {
//     int findMaxFreq(unordered_map<int,int>& freq){
//         int maxi=0;
//         for(pair<int,int> element: freq){
//             maxi=max(maxi,element.second);
//         }
//         return maxi;
//     }
// public:
//     int maxSubarrayLength(vector<int>& nums, int k) {
//         int n=nums.size();
//         int l=0;
//         int r=n-1;
//         unordered_map<int,int> freq;
//         for(int i=0; i<n; i++){
//             freq[nums[i]]++;
//         }
//         int maxfreq=findMaxFreq(freq);
//         while(l<=r && maxfreq>k){
//             if(freq[nums[r]]>k){
//                 freq[nums[r]]--;
//                 r--;
//             }
//             else if(freq[nums[l]]>k){
//                 freq[nums[l]]--;
//                 l++;
//             }
//             else if(l<=r && maxfreq>k){
//                 freq[nums[r]]--;
//                 r--;
//             }
//             maxfreq=findMaxFreq(freq);
//         }
//         return r-l+1;        
//     }
// };

class Solution {
public:
    int maxSubarrayLength(std::vector<int>& nums, int k) {
        // Intuition: only nums[right] itself can break the window, shrink from left until it fits again
        int n = nums.size();
        int r = 1;
        int left = 0;
        std::unordered_map<int, int> freq;
        for (int right = 0; right < n; right++) {
            int c = nums[right];
            freq[c]++;
            // Decrease window length until k constraint is true again
            while (freq[c] > k) {
                int d = nums[left];
                freq[d]--;
                left++;
            }
            r = std::max(r, right - left + 1);
        }
        return r;
    }
};