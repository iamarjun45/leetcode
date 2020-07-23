class Solution {
    vector<int> first;
    vector<int> last;
    string sameS;
    int checkSubstring(int start){
        // end will contain the valid substring end
        // currently, it contains the last occurence of s[start] 
        // because a valid substring should contain all the occurences of each character in it
        int end=last[sameS[start]-'a'];
        for(int i=start;i<=end;i++){
            // if there exist any occurence of s[i] before start, then it cant be a valid substring
            if(first[sameS[i]-'a']<start)
                return -1;
            // update end because of all the last occurence of each character in valid substring
            end=max(end,last[sameS[i]-'a']);
        }
        // return the index where the valid substring end
        return end;
    }
public:
    vector<string> maxNumOfSubstrings(string s) {
        // Same as S
        sameS=s;
        // Length of string S
        int n=s.length();
        // Storing the first occurence of each character
        first=vector<int>(26,INT_MAX);
        // Storing the last occurence of each character 
        last=vector<int>(26,INT_MIN);
        // Storing the valid substrings
        vector<string> output;
        for(int i=0;i<n;i++){
            first[s[i]-'a']=min(first[s[i]-'a'],i);
            last[s[i]-'a']=max(last[s[i]-'a'],i);
        }
        // Ending index of last valid Substring
        int lastEnd=INT_MAX;
        for(int i=0;i<n;i++){
            // If its the first occurence of s[i], then it might be a valid substring
            if(i==first[s[i]-'a']){
                // end will contain the index where the valid substring end
                int end=checkSubstring(i);
                // if end==-1, the valid substring doesn't exist
                if(end!=-1){
                    // if there is no overlapp, then this valid substring will be added as a new substring
                    if(i>lastEnd || output.size()==0){
                        output.push_back("");
                    }
                    // if there is overlapp, then the previous valid substring cant be included
                    // Now the Endind index will be updated to the current valid substring end
                    lastEnd=end;
                    // Now replace the last element of output with the current valid Substring
                    output.back()=s.substr(i,lastEnd-i+1);   
                }
            }
        }
        return output;
    }
};#include<bits/stdc++.h>
#define MOD 1000000007
#define int long long
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

void solve(){

}
int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}




