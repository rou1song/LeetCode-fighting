/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},
    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)
*/

//注意： 输出无重复项！ 
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
    	vector<vector<int> > ans;
    	if (num.size() < 3) return ans;
    	sort(num.begin(), num.end());
    
    	for (int i = 0; i < num.size() - 2; i++) {
    	    if (i > 0 && num[i] == num[i-1])                      //去重
    	        continue;
    	    
    	    int lo = i+1, hi = num.size()-1, sum = -num[i];
    	    while(lo < hi) {
    	        if(num[lo] + num[hi] == sum) {
    	            ans.push_back({num[i], num[lo], num[hi]});
    	            while(lo < hi && num[lo] == num[lo+1]) lo++;    //去重
    	            while(lo < hi && num[hi] == num[hi-1]) hi--;    //去重
    	            lo++; hi--;
    	        } else if(num[lo] + num[hi] < sum) lo++;
    	        else hi--;
    	    }
    	}
    	return ans;
    }
};
