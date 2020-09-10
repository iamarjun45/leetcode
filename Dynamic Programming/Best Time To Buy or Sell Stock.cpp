class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int price_length=prices.size();
        if(price_length==0)
            return price_length;
        int ans=0;
        int minimumValue=prices[0];
        for(int i=1;i<price_length;i++){
            minimumValue=min(minimumValue,prices[i]);
            ans=max(ans,prices[i]-minimumValue);
        }
        return ans;
    }
};
