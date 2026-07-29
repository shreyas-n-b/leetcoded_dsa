class Solution {
private: 
    int nCr(int n, int r, int k){
        r=min(r,n-r);
        long long result=1;
        for(int i=1; i<=r; i++){
            result = result*(n-r+i)/i;
            if(result>=k)return k;
        }
        return (int)result;
    }
    int countWays(vector<int>& count, int k){
        int letters=0;
        for(int i=0; i<26; i++){
            letters += count[i];
        }
        long long ways=1;
        for(int i=0; i<26; i++){
            if(count[i]>0){
                ways = ways*nCr(letters,count[i],k);
                letters -= count[i];
                if(ways >= k)return k;
            }
        }
        return (int)ways;
    }
public:
    string smallestPalindrome(string s, int k) {
        int n=s.size();
        char mid=' ';
        if(n%2==1){
            mid=s[n/2];
        }
        string halfResult="";
        int half=n/2;
        vector<int> count(26,0);

        for(int i=0; i<n; i++){
            if(n%2==1 && i==n/2)continue;
            count[s[i]-'a']++;
        }

        for(int i=0; i<26; i++)count[i] /= 2;

        int assigned=0;

        for(int j=0; j<half; j++){
            for(int i=0; i<26; i++){
                if(count[i]>0){
                    halfResult.push_back((char)('a'+i));
                    count[i]=count[i]-1;
                    int ways=countWays(count,k);
                    if(ways >= k){
                        assigned++;
                        break;
                    }
                    else{
                        halfResult.pop_back();
                        count[i]++;
                        k=k-ways;                        
                    }
                }
            }
        }

        string result="";
        if(assigned < half)return result;
        result += halfResult;
        if(n%2==1){
            result.push_back(mid);            
        }
        for(int i=half-1; i>=0; i--){
            result.push_back(halfResult[i]);
        }
        return result;
    }
};