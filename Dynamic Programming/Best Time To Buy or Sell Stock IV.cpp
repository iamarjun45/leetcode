class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int prices_length=prices.size();
        if(k==0 || prices_length<2)
            return 0;
        if(k>=prices_length/2){
            int ans=0;
            for(int i=1;i<prices_length;i++)
                ans=ans+(prices[i]>prices[i-1]?prices[i]-prices[i-1]:0);
            return ans;
        }
        vector<int> buy(k,INT_MAX),sell(k,0);
        for(int i=0;i<prices_length;i++){
            buy[0]=min(buy[0],prices[i]);
            sell[0]=max(sell[0],prices[i]-buy[0]);
            for(int j=1;j<k;j++){
                buy[j]=min(buy[j],prices[i]-sell[j-1]);
                sell[j]=max(sell[j],prices[i]-buy[j]);
            }
        }
        return sell[k-1];
    }
};
