class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        int maxi=0;
        priority_queue<int,vector<int>,greater<int>> minHeap;
        priority_queue<int> maxHeap;
        for(int i=0; i<n; i++){
            maxi=max(maxi,nums[i]);
            int gcd=__gcd(maxi,nums[i]);
            minHeap.push(gcd);
            maxHeap.push(gcd);
        }
        int iterations=n/2;
        long long sum=0;
        for(int i=0; i<iterations; i++){
            int larger=maxHeap.top();
            maxHeap.pop();
            int smaller=minHeap.top();
            minHeap.pop();
            sum += __gcd(larger,smaller);
        }
        return sum;
    }
};