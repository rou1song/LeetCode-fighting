/*

 Problem:    Search in Rotated Sorted Array II
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_81
 Notes:
 Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 What if duplicates are allowed?
 Would this affect the run-time complexity? How and why?
 Write a function to determine if a given target is in the array.
 Solution: Sequence search. O(n)
           Since there are duplicates, it's hard to decide which branch to go if binary-search is deployed.
 */

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size() == 0) 
            return false;
        int low = 0, high = nums.size() - 1;
        int mid;
        
        while(low <= high) {
            mid = low + (high - low)/2;
            if(nums[mid] == target) return true;
            if(nums[mid] > nums[low]) {
                if(target >= nums[low] && target < nums[mid]) 
                    high = mid - 1;
                else
                    low = mid + 1;
            } else if (nums[mid] < nums[low]) {
                    if(target > nums[mid] && target < nums[low]) 
                        low = mid + 1;
                    else
                        high = mid - 1;
            } else if (nums[mid] == nums[low]){
                low++;
            }
        }   
        return false;
    }
};
