class Solution {
public:
    int minimumPushes(string word) {
        vector<pair<char,int>> freq(26,{'\0',0});
        int distcnt=0;
        for(char letter: word){
            if(freq[letter-'a'].second == 0){
                distcnt++;
            }
            freq[letter-'a'].first=letter;
            freq[letter-'a'].second++;
        }
        sort(freq.begin(),freq.end(),[](const pair<char,int>&a, const pair<char,int>&b){
            if(a.second==b.second){
                return a.first<b.first;
            }
            return a.second > b.second;
        });
        int maxpresses=0;
        int temp=distcnt;
        while(temp/8 > 0){
            maxpresses++;
            temp = temp - 8;
        }
        int ans=0;
        int press=1;
        for(int i=0; i<distcnt; i+=8){
            int sum=0;
            for(int j=i; j<i+8; j++){
                if(j >= distcnt)break;
                sum += freq[j].second;
            }
            ans += press*sum;
            press++;
        }
        return ans;
    }
};
