class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result =0;
        int buy = prices[0];
        for(int i=0; i<prices.size();++i){
            if(prices[i]<buy){
                buy = prices[i];
            }
            result = max(result,prices[i] - buy);
        }

        return result;
    }
};