class Solution {
public:
    unordered_map<string,vector<string>>m;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if(m.find(s)!=m.end())
            return m[s];
        vector<string>v;
        for(auto x:wordDict){
            if(s.substr(0,x.length())==x){
                if(s.length()==x.length())
                    v.push_back(x);
                else{
                    vector<string>t=wordBreak(s.substr(x.length()),wordDict);
                    for(auto y:t)
                        v.push_back(x+" "+y);
                }
            }
        }
        m[s]=v;
        return v;
    }
};
