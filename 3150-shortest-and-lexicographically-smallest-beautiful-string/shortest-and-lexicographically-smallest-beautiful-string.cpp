// class Solution {
// public:
//     string shortestBeautifulSubstring(string s, int k) {
//         int i=0;
//         int j=k-1;
//         int n=s.length();
//         while(j<n){
//             int ones=countOnes(s,i,j);
//             while(j<n && ones<k){
//                 j++;
//                 ones=countOnes(s,i,j);
//             }
//             while(ones == k){
//                 //somehow store len=j-i+1 and s[i]...s[j]
//                 i++;
//                 ones=countOnes(s,i,j);
//             }
//             j++;
//         }
//         //return the lexicographically smallest string among all the strings that have length = least len        
//     }
// };
class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        int i = 0;
        int ones = 0;
        string ans = "";
        int minLen = INT_MAX;
        for (int j = 0; j < n; j++) {
            // Add s[j] to the window
            if (s[j] == '1') {
                ones++;
            }
            // We have more than k ones.
            // Move i until we have exactly k ones.
            while (ones > k) {
                if (s[i] == '1') {
                    ones--;
                }
                i++;
            }
            // We have exactly k ones.
            if (ones == k) {
                // Remove unnecessary leading zeroes.
                while (s[i] == '0') {
                    i++;
                }
                int len = j - i + 1;
                string curr = s.substr(i, len);
                if (len < minLen) {
                    minLen = len;
                    ans = curr;
                }
                else if (len == minLen && curr < ans) {
                    ans = curr;
                }
            }
        }
        return ans;
    }
};