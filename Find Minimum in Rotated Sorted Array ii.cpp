/*
 Problem:    Find Minimum in Rotated Sorted ArrayII
 Difficulty: Hard
 Source:     https://oj.leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
 Notes:
 Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 
 Find the minimum element.
 
 The array may contain duplicates.
*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int low = 0, high = nums.size() - 1;
        int mid;
        
        while(low < high) {
            mid = low + (high - low)/2;
            if(nums[mid] > nums[high])
                low = mid + 1;
            else if (nums[mid] < nums[high])
                high = mid;
            else if(nums[mid] == nums[high])
                high--;
        }
        return nums[low];
    }
};
