class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size();
        int ans=-1;
        for(int rowOffset=-n+1; rowOffset<n; rowOffset++){
            for(int colOffset=-n+1; colOffset<n; colOffset++){
                int cnt=0;
                for(int i=0; i<n; i++){
                    for(int j=0; j<n; j++){
                        int newi=i+rowOffset;
                        int newj=j+colOffset;
                        if(newi>=0 && newj>=0 && newi<n && newj<n){
                            int first=img1[i][j];
                            int second=img2[newi][newj];
                            if(first == 1 && second == 1){
                                cnt++;
                            }
                        }
                    }
                }
                ans=max(ans,cnt);
            }
        }
        return ans;        
    }
};