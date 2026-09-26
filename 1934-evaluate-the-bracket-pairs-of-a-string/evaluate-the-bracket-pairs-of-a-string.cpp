class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string> hm;
        int n=knowledge.size();
        for(int i=0; i<n; i++){
            hm[knowledge[i][0]]=knowledge[i][1];
        }
        int m=s.length();
        string res;
        for(int i=0; i<m; i++){
            if(s[i]=='('){
                int j=i+1;
                string key;
                while(j<m && s[j]!=')'){
                    key.push_back(s[j]);
                    j++;
                }
                i=j;
                if(hm.find(key)==hm.end()){
                    res.push_back('?');
                }else{
                    res += hm[key];
                }
            }else{
                res.push_back(s[i]);
            }
        }
        return res;        
    }
};