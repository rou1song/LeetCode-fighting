/*
 Problem:    Find Minimum in Rotated Sorted Array
 Difficulty: Medium
 Source:     https://oj.leetcode.com/problems/find-minimum-in-rotated-sorted-array/
 Notes:
 Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 
 Find the minimum element.
 
 You may assume no duplicate exists in the array.
*/
//网上大部分的做法，nums[mid] > nums[high]，和nums[high]做比较，而不是nums[low]
//如此可以不用判断单调递增的情况，因为递增也会一步步收敛到nums[low] ； 
//或者加一句到while循环条件里：while (low < high && nums[low] > nums[high]) 
class Solution1 {
public:
    int findMin(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int low = 0, high = nums.size() - 1;
        int mid;
        while(low < high ) {
            mid = (low + high)/2;
            if(nums[mid] > nums[high])
                low = mid + 1;
            else
                high = mid;
        }
        return nums[low];
    }
};
//左右都一步步往中间靠，时间：O（logn）
class Solution2 {
public:
    int findMin(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        
        int low = 0, high = nums.size() - 1;
        int mid = (low + high)/2;
        
        if(nums[low] < nums[high])    //判断单调递增的情况
            return nums[low];
        while(high - low > 1) {
            mid = (low + high)/2;
            if(nums[mid] > nums[low])
                low = mid;
            else
                high = mid;
        }
        return nums[high];
    }
};
// 解一 nums[mid] >= nums[low]，写成和nums[low]比较的形式
class Solution3 {
public:
    int findMin(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        
        int low = 0, high = nums.size() - 1;
        int mid;

        while(low < high ) {
            if(nums[low] < nums[high]) 
                return nums[low];
            mid = (low + high)/2;
            if(nums[mid] >= nums[low])
                low = mid + 1;
            else
                high = mid;
        }
        return nums[low];
    }
};
