class Solution {
    vector<string> result;
    void f(int open, int close, string& ans, int n){
        if(ans.length() == 2*n){
            result.push_back(ans);
            return;
        }
        if(open < n){
            ans.push_back('(');
            f(open+1, close, ans, n);
            ans.pop_back();
        }
        if(close < open){
            ans.push_back(')');
            f(open, close+1, ans, n);
            ans.pop_back();
        }
        return;
    }
public:
    vector<string> generateParenthesis(int n) {
        string ans="";
        f(0,0,ans,n);
        return result;
    }
};