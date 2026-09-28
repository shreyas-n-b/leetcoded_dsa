class Solution {
public:
    int maxDepth(string s) {
        int maxi=0;
        int n=s.length();
        stack<int> st;
        for(int i=0; i<n; i++){
            if(s[i] != '(' && s[i] != ')')continue;
            if(s[i]=='('){
                st.push(s[i]);
            }else{
                st.pop();
            }
            maxi=max(maxi,(int)st.size());
        }
        return maxi;        
    }
};