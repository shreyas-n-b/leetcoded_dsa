// class Solution {
// public:
//     int minAddToMakeValid(string s) {
//         int openings=0;
//         int n=s.length();
//         int stackSize=0;
//         for(int i=0; i<n; i++){
//             if(s[i]=='('){
//                 if(stackSize==0){
//                     openings++;
//                 }else{
//                     stackSize--;
//                 }
//             }else{
//                 stackSize++;
//             }
//         }
//         return stackSize+openings;        
//     }
// };
class Solution {
public:
    int minAddToMakeValid(string s) {
        int count = 0;
        int result = 0;

        for (char ch : s) {
            if (ch == '(') {
                count++;
            } else {
                if (count > 0) {
                    count--;
                } else {
                    result++;
                }
            }
        }

        return result + count;
    }
};