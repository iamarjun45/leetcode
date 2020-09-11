class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int s_length=s.size();
        bool dp[s_length+1];
        dp[0]=true;
        for(int i=1;i<=s_length;i++){
            dp[i]=false;
            for(auto x:wordDict){
                int word_length=x.size();
                if(word_length>i)
                    continue;
                if(x==s.substr(i-word_length,word_length))
                    dp[i]|=dp[i-word_length];
            }
        }
        return dp[s_length];
    }
};
