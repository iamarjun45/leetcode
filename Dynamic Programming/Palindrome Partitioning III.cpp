class Solution {
public:
    int minCut(string s) {
        int size=s.size();
        bool dp[size][size];
        memset(dp,false,sizeof(dp));
        for(int i=0;i<size;i++) dp[i][i]=true;
        for(int i=0;i<size-1;i++)
            dp[i][i+1]= (s[i]==s[i+1]);
        
        for(int l=2;l<size;l++){
            for(int i=0;i<size-l;i++){
                int j=i+l;
                if(dp[i+1][j-1] && s[i]==s[j]){
                    
                    dp[i][j]=true;
                }
            }
        }
        int numCuts[size];
        for(int i=0;i<size;i++){
            if(dp[0][i])
                numCuts[i]=0;
            else{
                numCuts[i]=INT_MAX;
                for(int j=1;j<=i;j++){
                    if(dp[j][i])
                        numCuts[i]=min(numCuts[i],numCuts[j-1]+1);
                }
            }
        }
        return numCuts[size-1];
    }
};
