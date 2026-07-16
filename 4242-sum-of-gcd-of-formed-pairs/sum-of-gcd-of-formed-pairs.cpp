class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        int maxi=0;
        vector<int> prefixGcd(n);
        for(int i=0; i<n; i++){
            maxi=max(maxi,nums[i]);
            prefixGcd[i]=__gcd(maxi,nums[i]);
        }
        sort(prefixGcd.begin(),prefixGcd.end());
        int front=0;
        int back=n-1;
        long long sum=0;
        while(front < back){
            sum += __gcd(prefixGcd[front],prefixGcd[back]);
            front++;
            back--;
        }
        return sum;
    }
};