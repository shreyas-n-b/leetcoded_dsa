// class Solution {
//     int findSeq(int i, string&s, string& curr, unordered_set<string>& hs, vector<int>& dp){
//         int ans=0;
//         if(i==s.length()){
//             if(hs.count(curr)==0)ans=1;
//             hs.insert(curr);
//             return ans;
//         }
//         if(dp[i]!=-1)return dp[i];
//         //pick
//         curr.push_back(s[i]);
//         ans += findSeq(i+1,s,curr,hs,dp);
//         curr.pop_back();
//         //nopick
//         ans += findSeq(i+1,s,curr,hs,dp);
//         return dp[i]=ans;
//     }
// public:
//     int distinctSubseqII(string s) {
//         int n=s.length();
//         unordered_set<string> hs;
//         vector<int> dp(n,-1);
//         string curr="";
//         int result=findSeq(0,s,curr,hs,dp);
//         return result-1;        
//     }
// };
class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;
        
        long long endsWith[26] = {0};
        long long total = 0; 
        for (char ch : s) {
            int idx = ch - 'a';
            
            long long newForCh = (total + 1) % MOD;
            
            total = (total - endsWith[idx] + newForCh) % MOD;
            if (total < 0) {
                total += MOD;
            }
            
            endsWith[idx] = newForCh;
        }
        
        return total;
    }
};