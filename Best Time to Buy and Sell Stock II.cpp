/*
 Problem:    Best Time to Buy and Sell Stock II
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_122
 Notes:
 Say you have an array for which the ith element is the price of a given stock on day i.
 Design an algorithm to find the maximum profit. You may complete as many transactions as you like 
 (ie, buy one and sell one share of the stock multiple times). 
 However, you may not engage in multiple transactions at the same time 
 (ie, you must sell the stock before you buy again).
 */
 
 // Solution: 1. 每次遇到连续上升的区间，用while循环，得到本段上升的 profit
              At the ending of the ascending order: sell.
              2. For ascending order [1,2,4], (4 - 1) == (2 - 1) + (4 - 2).
              
class Solution1 {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1) return 0;
        int minprice = INT_MAX;
        int profit = 0;
        int low = 0, high = prices.size()-1;
        while(low < high) {
            minprice = prices[low];
            while(low < high && prices[low] < prices[low+1]) low++;
            profit += prices[low] - minprice;
            low++;
        }
        return profit;
    }
};

class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1) return 0;
        int minprice = prices[0];
        int profit = 0;

        for(int i = 1; i < prices.size(); i++) {
            if(prices[i] > prices[i-1]) 
                profit += prices[i] - prices[i-1];
        }
        return profit;
    }
};
