class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        if(n<1)return 0;
        int l=0;
        int r=0;
        unordered_set<char> visited;
        visited.insert(s[r]);
        r++;
        int ans=1;
        while(r<n && l<=r){
            if(visited.count(s[r])>0){
                while(l<=r && s[l]!=s[r]){
                    visited.erase(s[l]);
                    l++;
                }
                if(l<n){
                    visited.erase(s[l]);
                    l++;
                }
            }
            ans=max(ans,r-l+1);
            visited.insert(s[r]);
            r++;
        }
        return ans;        
    }
};