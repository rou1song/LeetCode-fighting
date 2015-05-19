/*
 Problem:    Best Time to Buy and Sell Stock
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_121
 Notes:
 Say you have an array for which the ith element is the price of a given stock on day i.
 If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), 
 design an algorithm to find the maximum profit.
 */
 
 //Solution: 找到下一个比现在的minp更小的点
 //方法1：然后更新 prices[i] - minP;  方法2： 然后置maxP = 0； 计算下一段的最大profit = max(profit, maxP - minP);
 
class Solution {
public:
  	int maxProfit(vector<int>& prices) {
		if (prices.size() <= 1) return 0;
		int profit = 0;
		int minP = prices[0];
		
		for (int i = 1; i < prices.size(); i++) {
			if (prices[i] < minP) 
				minP = prices[i];
			else 
			    profit = max(profit, prices[i] - minP);
		}
		return profit;
	}
};

class Solution2 {
public:
  	int maxProfit(vector<int>& prices) {
		if (prices.size() <= 1) return 0;
		int maxP = 0, minP = INT_MAX;
		int profit = 0;
	
		for (int i = 0; i < prices.size(); i++) {
			if (prices[i] > maxP) {
				maxP = prices[i];
			}
			if (prices[i] < minP) {
				minP = prices[i];
				maxP = 0;
			}
			profit = max(profit, maxP - minP);
		}
		return profit;
	}
};
