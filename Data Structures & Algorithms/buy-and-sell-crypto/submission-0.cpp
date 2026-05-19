class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result =0;
        for(int i = 0;i<prices.size();i++){
            int buys=prices[i];
        for(int j = i+1;j<prices.size();j++){
            int sell=prices[j];
    result=max(result,sell-buys);
        }
        }
        return result;
    }
};
