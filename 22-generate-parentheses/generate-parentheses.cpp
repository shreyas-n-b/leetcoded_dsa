class Solution {
    void solve(int open, int close, string& s, int n, vector<string>& ans){
        if(s.length()==2*n){
            ans.push_back(s);
            return;
        }
        if(open<n){
            s.push_back('(');
            solve(open+1,close,s,n,ans);
            s.pop_back();
        }
        if(close<open){
            s.push_back(')');
            solve(open,close+1,s,n,ans);
            s.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s="";
        solve(0,0,s,n,ans);
        return ans;        
    }
};