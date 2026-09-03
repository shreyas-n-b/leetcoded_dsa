class Solution {
    void constructnse(vector<int>& nse, vector<int>& nums){
        int n=nums.size();
        stack<int> st;
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
            }
            if(st.empty())nse[i]=-1;
            else nse[i]=st.top();
            if(nums[i]%2 != 0)st.push(i);
        }
        return;
    }

    void constructpse(vector<int>& pse, vector<int>& nums){
        int n=nums.size();
        stack<int> st;
        for(int i=0; i<n; i++){
            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
            }
            if(st.empty())pse[i]=-1;
            else pse[i]=st.top();
            if(nums[i]%2 != 0)st.push(i);
        }
        return;
    }
public:
    bool uniformArray(vector<int>& nums1) {
        int evencnt=0;
        int oddcnt=0;
        int n=nums1.size();
        for(int i=0; i<n; i++){
            if(nums1[i]%2==0){
                evencnt++;
            }else{
                oddcnt++;
            }
        }
        if(evencnt==n || oddcnt==n)return true;
        vector<int> nse(n);
        vector<int> pse(n);
        constructnse(nse,nums1);
        constructpse(pse,nums1);
        for(int i=0; i<n; i++){
            if(nums1[i]%2==0){
                bool check=(nse[i]!=-1) || (pse[i]!=-1);
                if(check == false)return false;
            }
        }
        return true;        
    }
};