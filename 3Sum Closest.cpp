/*
    Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

class Solution {
public:
    int threeSumClosest(vector<int>& num, int target) {
        int ans, sum;
        if(num.size() <= 3) 
            return accumulate(num.begin(), num.end(), 0);
        sort(num.begin(), num.end());
        ans = num[0] + num[1] + num[2];
        for(int i = 0; i < num.size()-2; i++) {
            int low = i + 1, high = num.size() - 1;
            while(low < high) {
                sum = num[i] + num[low] + num[high];
                if(abs(target - sum) < abs(target - ans)) 
                    ans = sum;
                if(sum == target) return target;
                else if(sum < target) low++;
                else high--;
            }
        }
        return ans;
    }
};
