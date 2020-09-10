class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int firstBuy=INT_MAX,firstProfit=0,secondBuy=INT_MAX,secondProfit=0;
        for(auto x:prices){
            firstBuy=min(firstBuy,x);
            firstProfit=max(firstProfit,x-firstBuy);
            secondBuy=min(secondBuy,x-firstProfit);
            secondProfit=max(secondProfit,x-secondBuy);
        }
        return secondProfit;
    }
};
