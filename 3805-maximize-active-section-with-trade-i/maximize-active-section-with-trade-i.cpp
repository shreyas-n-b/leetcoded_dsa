class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int activeCount=count(s.begin(),s.end(),'1');
        int i=0;
        vector<int> activeSession;
        int n=s.size();
        while(i<n){
            if(s[i]=='0'){
                int start=i;
                while(i<n && s[i]=='0')i++;
                activeSession.push_back(i-start);
            }else{
                i++;
            }
        }
        int maxPairSum=0;
        for(int i=1; i<activeSession.size(); i++){
            maxPairSum=max(maxPairSum,(activeSession[i]+activeSession[i-1]));
        }
        //cout<<maxPairSum<<" "<<activeCount<<endl;
        return maxPairSum+activeCount;        
    }
};