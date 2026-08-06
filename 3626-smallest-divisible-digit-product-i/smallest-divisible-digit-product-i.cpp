class Solution {
public:
    int smallestNumber(int n, int t) {
        int ans=n;
        while(true){
            int p=1;
            int temp=ans;
            while(temp>0){
                p=p*(temp%10);
                temp=temp/10;
            }
            if(p%t==0){
                return ans;
            }else{
                ans++;
            }
        }
        return 0;        
    }
};