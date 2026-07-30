class Solution {
public:
    int maxProduct(int n) {
        vector<int> digits;
        int temp=n;
        while(temp>0){
            digits.push_back(temp%10);
            temp=temp/10;
        }
        //first pass
        int maxi=-1;
        int firstind=-1;
        for(int i=0; i<digits.size(); i++){
            if(digits[i]>maxi){
                maxi=digits[i];
                firstind=i;
            }
        }
        int first=maxi;
        //second pass
        maxi=-1;
        for(int i=0; i<digits.size(); i++){
            if(i==firstind)continue;
            if(digits[i]>maxi){
                maxi=digits[i];
            }
        }
        int second=maxi;
        return first*second;             
    }
};