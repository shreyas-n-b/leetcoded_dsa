class Solution {
public:
    int minimumPushes(string word) {
        int n=word.length();
        int presses=1;
        const int keys=8;
        int ans=0;

        while(n/keys > 0){
            ans += (presses*keys);
            presses++;
            n = n-keys;
        }

        ans = ans + (presses*n);
        return ans;        
    }
};