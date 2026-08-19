class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        sort(reservedSeats.begin(),reservedSeats.end(),[](const vector<int>& a, const vector<int>& b){
            if(a[0]==b[0]){
                return a[1]<b[1];
            }
            return a[0]<b[0];
        });
        vector<bool> groups;
        int ans=0;
        int l=reservedSeats.size();
        int i=0;
        int reservedRows=0;
        while(i<l){
            groups.assign(3,true);
            int row=reservedSeats[i][0];
            reservedRows++;
            while(i<l && reservedSeats[i][0]==row){
                int seat=reservedSeats[i][1];
                if(seat>=2 && seat<=5){
                    groups[0]=false;
                }
                if(seat>=4 && seat<=7){
                    groups[1]=false;
                }
                if(seat>=6 && seat<=9){
                    groups[2]=false;
                }
                i++;
            }
            int cnt=0;
                if(groups[0] && groups[2]){
                    cnt=2;
                }
                else if(groups[0] || groups[1] || groups[2]){
                    cnt=1;
                }

                ans += cnt;
        }
        int unreservedRows=n-reservedRows;
        return ans+2*unreservedRows;        
    }
};