class Solution {
public:
    long long countCommas(long long n) {
        vector<int> commasFor={-1,0,0,0,1,1,1,2,2,2,3,3,3,4,4,4,5,5,5};
        long long temp=n;
        int digitsCnt=0;
        while(temp>0){
            digitsCnt++;
            temp=temp/10;
        }
        int m=digitsCnt-1;
        cout<<digitsCnt;
        long long result=0;
        while(m>3){
            result += 9LL*pow(10,m-1)*commasFor[m];
            m--;
        }
        if(digitsCnt>3)result += (n-pow(10,digitsCnt-1)+1)*commasFor[digitsCnt];
        return result;        
    }
};