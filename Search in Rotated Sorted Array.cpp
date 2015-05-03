/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/

class Solution {
public:
    int search(int A[], int n, int target) {
        int low = 0;
        int high = n-1;
        int mid;
        while(low <= high){
            mid = (low + high)/2;
            if(A[mid] == target) return mid;

            if(A[low] <= A[mid]){                           //此处为 <= ,可能只有1个元素
                if(target < A[mid] && target >= A[low] ) high = mid - 1;
                else low = mid + 1;
            } else {
                if(target > A[mid] && target < A[low]) low = mid + 1;
                else high = mid - 1;
            }
        }
        return -1;
    }
};
