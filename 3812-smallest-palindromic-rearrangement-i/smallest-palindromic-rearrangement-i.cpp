class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.size();
        vector<char> ans(n);
        int l=0;
        int r=n-1;
        const int base=97;

        int freq[26]={0};
        for(char ch: s){
            freq[ch-'a']++;
        }

        for(int i=0; i<26; i++){
            while(freq[i]>=2){
                ans[l]=(char)(base+i);
                ans[r]=ans[l];
                l++;
                r--;
                freq[i] -= 2;
            }
        }

        for(int i=0; i<26; i++){
            if(freq[i]>0){
                ans[l]=(char)(base+i);
                l++;
            }
        }

        string res(ans.begin(),ans.end());
        return res;
        
    }
};