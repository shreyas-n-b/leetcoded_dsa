class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        const unordered_map<char, int> mapping={
            {'(',1},
            {')',-1},
            {'[',2},
            {']',-2},
            {'{',3},
            {'}',-3}
        };
        int sum=0;
        for(char ch: s){
            if(mapping.at(ch)>0){
                st.push(ch);
            }else{
                if(st.empty())return false;
                if(mapping.at(ch)+mapping.at(st.top()) != 0)return false;
                st.pop();
            }
            sum += mapping.at(ch);
        }
        return (sum == 0);        
    }
};