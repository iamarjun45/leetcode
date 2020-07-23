class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
    	// Since all the bottles are filled, we can drink them
        int ans=numBottles;
        // Now all the bottles are empty
        int emptyBottles=numBottles;
        // We will move till we are bound to exchange
        while(emptyBottles>=numExchange){
        	// No exchange possible
            int stillEmpty=emptyBottles%numExchange;
            // Number of filled bottles exchanged for emptyBottles
            int exchanged=emptyBottles/numExchange;
            // Drink the filled bottles
            ans=ans+exchanged;
            // Total empty Bottles=stillEmptyBottles+exchangedBottles
            emptyBottles=stillEmpty+exchanged;
        }
        return ans;
    }
};
