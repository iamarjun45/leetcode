class Solution {
public:
    int numSub(string s) {
        // To store the count of consecutive 1's
        int currCount=0;
        // To store the total number of substrings with all 1's
        int totalSubs=0;
        for(auto x:s){
            if(x=='1'){
                currCount++;
                totalSubs=(totalSubs+currCount)%1000000007;
            }else{
                // O found. Hence, no 1's currently together.
                currCount=0;
            }
        }
        return totalSubs;
    }
};
