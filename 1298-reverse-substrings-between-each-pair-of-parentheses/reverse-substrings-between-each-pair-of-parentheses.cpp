class Solution {
    void swap(char& c1, char& c2){
        char temp=c1;
        c1=c2;
        c2=temp;
        return;
    }
public:
    string reverseParentheses(string s) {
        int n=s.length();
        string temps=s;
        int cnt=0;
        for(int i=0; i<n; i++){
            if(s[i]=='(')cnt++;
        }
        for(int itr=0; itr<cnt; itr++){
            int openind=0;
            int closeind=-1;
            for(int i=0; i<temps.size(); i++){
                if(temps[i]=='('){
                    openind=i;
                }
                if(temps[i]==')' && closeind<openind){
                    closeind=i;
                }
            }
            for(int j=1; j<=(closeind-openind)/2; j++){
                swap(temps[openind+j],temps[closeind-j]);
            }
            string temp2s=temps;
            temps="";
            for(int i=0; i<temp2s.size(); i++){
                if(i==openind || i==closeind)continue;
                temps.push_back(temp2s[i]);
            }
        }
        return temps;        
    }
};