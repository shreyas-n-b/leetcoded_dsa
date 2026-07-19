class Solution {
public:
    string smallestSubsequence(string s) {
        vector<bool> taken(26,false);
        vector<int> lastIndex(26,-1);
        for(int i=0; i<s.length(); i++){
            lastIndex[s[i]-'a']=i;
        }
        vector<char> res;
        res.push_back(s[0]);
        taken[s[0]-'a']=true;
        for(int i=1; i<s.length(); i++){
            if(taken[s[i]-'a'])continue;
            while(res.size()>0){
                char lastChar=res.back();
                if(lastIndex[lastChar-'a']>i && (s[i]-lastChar)<0){
                    taken[lastChar-'a']=false;
                    res.pop_back();
                }
                else{
                    break;
                }
            }
            res.push_back(s[i]);
            taken[s[i]-'a']=true;
        }
        string ans(res.begin(), res.end());
        return ans;        
    }
};