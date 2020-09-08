unordered_map<string,int> u;
class Solution{
public:
    bool isScramble(string s1, string s2) {
        if(s1==s2)
            return true;
        if(s1.length()!=s2.length() || s1.length()<=1 || s2.length()<=1)
            return false;
        if(u.find(s1+" "+s2)!=u.end())
            return u[s1+" "+s2];
        for(int k=0;k<s1.length()-1;k++){
            bool ans1=isScramble(s1.substr(0,k+1),s2.substr(0,k+1)) && isScramble(s1.substr(k+1),s2.substr(k+1));
            bool ans2=isScramble(s1.substr(0,k+1),s2.substr(s2.length()-k-1)) && isScramble(s1.substr(k+1),s2.substr(0,s2.length()-k-1));
            if(ans1 || ans2){
                return u[s1+" "+s2]=true;
            }
        }
        return u[s1+" "+s2]=false;
    }
};
