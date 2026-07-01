class Solution {
public:
    int maxProfit(vector<int>& today_price) {
        int min_price = INT_MAX;   // sabse sasta buy price
        int max_profit = 0;        // ab tak ka best profit

        for (int i = 0; i < today_price.size(); i++) {
            // sabse sasta price update karo
            if (today_price[i] < min_price) {
                min_price = today_price[i];
            }

            // agar aaj sell karte toh profit kitna hota
            int profit = today_price[i] - min_price;

            // max profit update karo
            if (profit > max_profit) {
                max_profit = profit;
            }
        }

        return max_profit;
    }
};
