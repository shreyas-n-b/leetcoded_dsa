class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n=digits.size();
        unordered_set<int> hs;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i==j)continue;
                for(int k=0; k<n; k++){
                    if(j==k || i==k)continue;
                    int result=digits[i]*100+digits[j]*10+digits[k];
                    if((result%2 == 0) && (result/100 > 0)){
                        hs.insert(result);
                    }
                }
            }
        }
        return hs.size();        
    }
};