class Solution {
public:
    int reverseDegree(string s) {
        int n=s.length();
        vector<int> revOrder(26);
        for(int i=0; i<26; i++)revOrder[i]=26-i;
        int ans=0;
        for(int i=0; i<n; i++){
            ans += revOrder[s[i]-'a']*(i+1);
        }
        return ans;        
    }
};