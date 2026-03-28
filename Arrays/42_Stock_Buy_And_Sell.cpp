/* You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Input: prices = [7, 1, 5, 3, 6, 4]
Output: 5
Explaination: Buy on day 2 (price = 1) and sell on day 5 (price = 6) profit = 6-1 = 5.

Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

Input: prices = [7, 6, 4, 3, 1]
Output: 0
Explaination: In this case, no transactions are done and the max profit = 0.
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    int maxProfit(vector<int>& prices){
        int maxProfit = 0, bestBuy = prices[0];

        for(int i=1; i<prices.size(); i++){
            if(prices[i] > bestBuy){
                maxProfit = max(maxProfit, prices[i]-bestBuy);
            }
            bestBuy = min(bestBuy, prices[i]);
        }
        return maxProfit;
    }
};

int main(){
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;

    vector<int> prices(n);
    cout<<"Enter the value of prices: ";
    for(int i=0; i<n; i++){
        cin>>prices[i];
    }

    Solution sol;
    int result = sol.maxProfit(prices);
    cout<<"Maxprofit: "<<result<<endl;

    return 0;
}