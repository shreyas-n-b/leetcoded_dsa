class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int d=0;
        int n=seq.length();
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(seq[i]=='('){
                d++;
                if(d%2==1)ans.push_back(1);
                else ans.push_back(0);
            }else{
                if(d%2==1){
                    ans.push_back(1);
                }else ans.push_back(0);
                d--;
            }
        }
        return ans;        
    }
};