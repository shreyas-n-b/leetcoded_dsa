class Solution {
public:
    string frequencySort(string s) {
        const char baseDigit='0';
        const char baseCharUpper='A';
        const char baseCharLower='a';
        int digitStartind=52;
        int lowerStartind=26;
        vector<pair<char,int>> vec(62);
        for(int i=0; i<62; i++){
            if(i>=digitStartind){
                vec[i].first=baseDigit+(i-digitStartind);
                vec[i].second=0;
            }
            else if(i>=lowerStartind){
                vec[i].first=baseCharLower+(i-lowerStartind);
                vec[i].second=0;
            }
            else{
                vec[i].first=baseCharUpper+i;
                vec[i].second=0;
            }
        }

        for(char ch: s){
            if(isdigit(ch)){
                vec[digitStartind + (ch-baseDigit)].second++;
            }
            else if(isupper(ch)){
                vec[ch-baseCharUpper].second++;
            }
            else{
                vec[lowerStartind+(ch-baseCharLower)].second++;
            }
        }

        sort(vec.begin(), vec.end(), [](const pair<char,int>& a, const pair<char,int>& b){
            if(a.second == b.second){
                return a.first < b.first;
            }
            return a.second > b.second;
        });

        string ans="";
        for(int i=0; i<62; i++){
            if(vec[i].second > 0){
                while(vec[i].second > 0){
                    ans.push_back(vec[i].first);
                    vec[i].second--;
                }
            }else{
                break;
            }
        }
        return ans;
    }       
};