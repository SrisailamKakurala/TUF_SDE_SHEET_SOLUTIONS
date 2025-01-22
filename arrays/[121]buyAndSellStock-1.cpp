class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit = 0; // initially maxProfit is 0
        int min = INT_MAX; // minvalue is INT_MAX
        for(int i=0; i<n; i++) { // loop from 0 to n
            if(prices[i] < min) { // if the curr price is < min 
                min = prices[i]; // update min
            }
            // calc the diff b/w the min and currPrice at each iteration
            int diff = abs(min - prices[i]); 
            // compare and update the maxProfit
            maxProfit = max(maxProfit, diff);
        }
        return maxProfit; //return
    }
};



// #include<map>
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         int maxProfit = INT_MIN, profit = 0;
//         map<int, int> m;
//         for(int i=0; i<n; i++) {
//             m[prices[i]] = i;
//         }
//         auto i = m.begin();
//         auto j = m.end();
//         while(i!=j) {
//             if( i->second < j->second ) {
//                 profit = j->first - i->first;
//                 maxProfit = max(profit, maxProfit);
//             }else {
//                 j--;
//             }
//         }
//         return profit>maxProfit ? profit : maxProfit;
//     }
// };