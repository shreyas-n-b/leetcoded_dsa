class Solution {
    long long MOD=7+1e9;
    vector<vector<long long>> cTable;
    void populateTable(int n){
        for(int j=0; j<n+1; j++){
            vector<long long> row(j+1,1);
            cTable.push_back(row);
            for(int i=1; i<j; i++){
                cTable[j][i]=(cTable[j-1][i]+cTable[j-1][i-1])%MOD;
            }
        }       
    }
    long long solve(vector<int> nums){
        int n=nums.size();
        if(n<3)return 1;
        int root=nums[0];
        vector<int> left_array,right_array;
        for(int i=1; i<n; i++){
            if(nums[i]<root){
                left_array.push_back(nums[i]);
            }else{
                right_array.push_back(nums[i]);
            }
        }
        long long x=solve(left_array);
        long long y=solve(right_array);
        long long z=cTable[n-1][left_array.size()];
        return (((z*x)%MOD)*y)%MOD;
    }
public:
    int numOfWays(vector<int>& nums) {
        populateTable(nums.size());
        return (int)solve(nums)-1;        
    }
};