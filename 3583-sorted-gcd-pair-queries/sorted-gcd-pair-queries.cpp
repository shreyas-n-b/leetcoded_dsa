class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int m=*max_element(nums.begin(),nums.end());
        vector<int> answer;
        vector<long long> count(m+1,0);
        int n=nums.size();
        for(int i=0; i<n; i++){
            int num=nums[i];
            for(int j=1; j*j<=num; j++){
                if(num%j==0){
                    count[j]++;
                    if(j*j != num){
                        count[num/j]++;
                    }
                }
            }
        }
        for(int i=0; i<=m; i++){
            if(count[i]>=2){
                count[i]=(count[i]*(count[i]-1))/2;
            }
            else{
                count[i]=0;
            }
        }
        for(int j=m; j>=1; j--){
            if(count[j] == 0)continue;
            for(int k=2; j*k<=m; k++){
                int ele=j*k;
                if(count[ele]>0){
                    count[j] -= count[ele];
                }
            }
        }
        for(int j=1; j<=m; j++){
            count[j] = count[j]+count[j-1];
        }
        //Binary search on prefix array
        for(long long query: queries){
            long long target=query+1;
            int low=0;
            int high=m;
            int ans;
            while(low <= high){
                int mid=low + (high-low)/2;
                if(count[mid]>=target){
                    ans=mid;
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            answer.push_back(ans);
        }
        return answer;
    }
};