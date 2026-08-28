// class Solution {
//     void generate(string &s, string &curr, vector<bool> &used, unordered_set<string>& hs) {
//     if (curr.size() == s.size()) {
//         hs.insert(curr);
//         return;
//     }
//     for (int i = 0; i < s.size(); i++) {
//         if (used[i])
//             continue;
//         used[i] = true;
//         curr.push_back(s[i]);
//         generate(s,curr,used,hs);
//         curr.pop_back();
//         used[i] = false;
//     }
// }
// public:
//     string lexPalindromicPermutation(string s, string target) {
//         int n=s.length();
//         vector<int> freq(26,0);
//         for(int i=0; i<n; i++){
//             freq[s[i]-'a']++;
//         }
//         if(n%2==0){
//             for(int i=0; i<26; i++){
//                 if(freq[i]%2==1)return "";
//             }
//         }
//         else{
//             int cnt=0;
//             for(int i=0; i<26; i++){
//                 if(freq[i]%2==1){
//                     cnt++;
//                 }
//             }
//             if(cnt!=1)return "";
//         }
//         string shalf="";
//         char midChar='\0';
//         for(int i=0; i<26; i++){
//             if(freq[i]%2==1){
//                 midChar='a'+i;
//                 freq[i]--;
//             }
//             while(freq[i]>0){
//                 shalf.push_back(i+'a');
//                 freq[i] -= 2;
//             }
//         }
//         vector<bool> used(shalf.length(),false);
//         string curr="";
//         unordered_set<string> hs;
//         generate(shalf,curr,used,hs);
//         //
//         string ans="{";
//         for(string str: hs){
//             string half=str;
//             if(midChar!='\0')str.push_back(midChar);
//             for(int i=half.length()-1; i>=0; i--){
//                 str.push_back(half[i]);
//             }
//             if(str>target && str<ans){
//                 ans=str;
//             }
//         }
//         return (ans!="{")?ans:"";        
//     }
// };
class Solution {
public:
    string lexPalindromicPermutation(string str, string target) {
        int freq[26] = {0};
        for (char s : str)
            freq[s - 'a']++;

        char center = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2) {
                if (center != 0)
                    return "";
                center = 'a' + i;
                freq[i]--;
            }
        }

        int sz = str.length();
        int half = sz / 2;
        for (int i = 0; i < half; i++)
            freq[target[i] - 'a'] -= 2;

        if (check(freq)) {
            string head = target.substr(0, half);
            string rev = head;
            reverse(rev.begin(), rev.end());
            string tail = "";
            if (center != 0)
                tail += center;
            tail += rev;
            if (tail > target.substr(half))
                return head + tail;
        }

        for (int i = half - 1; i >= 0; i--) {
            char w = target[i];
            freq[w - 'a'] += 2;
            if (!check(freq))
                continue;

            for (int j = (w - 'a') + 1; j < 26; j++) {
                if (freq[j] == 0)
                    continue;
                freq[j] -= 2;
                string result = target.substr(0, i + 1);
                result[i] = 'a' + j;

                for (int k = 0; k < 26; k++) {
                    int cnt = freq[k] / 2;
                    if (cnt > 0)
                        result.append(cnt, 'a' + k);
                }

                string part = result;
                reverse(part.begin(), part.end());
                if (center != 0)
                    result.push_back(center);
                result += part;
                return result;
            }
        }

        return "";
    }

    bool check(int f[]) {
        for (int i = 0; i < 26; i++)
            if (f[i] < 0)
                return false;
        return true;
    }
};