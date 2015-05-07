/*
 Problem:    Maximum Product Subarray
 Difficulty: Medium
 Source:     https://oj.leetcode.com/problems/maximum-product-subarray/
 Notes:
 Find the contiguous subarray within an array (containing at least one number) which has the largest product.
 For example, given the array [2,3,-2,4],
 the contiguous subarray [2,3] has the largest product = 6.
*/
//注：易犯的错：不用curmin， curmax两个变量暂存的话，第一次激素阿森纳的minp结果会作用到maxp的计算中
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        
        int minp = nums[0], maxp = nums[0], ans = nums[0];
        int curmax, curmin;
        
        for(int i = 1; i < nums.size(); i++) {
            curmin = min( min(nums[i] * minp, nums[i] * maxp), nums[i]);
            curmax = max( max(nums[i] * minp, nums[i] * maxp), nums[i]);
            minp = curmin;
            maxp = curmax;
            ans = max(ans, maxp);
        }
        return ans;
    }
};
