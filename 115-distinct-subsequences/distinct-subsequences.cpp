// class Solution {
//     int cnt;
//     void generateSubsequence(int ind, string& s, string& t, string& curr){
//         if(curr==t){
//             cnt++;
//             return;
//         }
//         if(ind==s.length()){
//             return;
//         }
//         curr.push_back(s[ind]);
//         generateSubsequence(ind+1,s,t,curr);
//         curr.pop_back();
//         generateSubsequence(ind+1,s,t,curr);
//     }
// public:
//     int numDistinct(string s, string t) {
//         cnt=0;
//         string curr="";
//         generateSubsequence(0,s,t,curr);
//         return cnt;        
//     }
// };
class Solution {
    vector<vector<long long>> dp;

    long long solve(int i, int j, string& s, string& t) {
        // Successfully formed all of t
        if (j == t.length())
            return 1;
        // Ran out of s before forming t
        if (i == s.length())
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        // Don't take s[i]
        long long ans = solve(i + 1, j, s, t);
        // Take s[i], only if it matches t[j]
        if (s[i] == t[j])
            ans += solve(i + 1, j + 1, s, t);
        return dp[i][j] = ans;
    }
public:
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        dp.assign(n, vector<long long>(m, -1));
        return solve(0, 0, s, t);
    }
};