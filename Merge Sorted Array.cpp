/*
 Problem:    Merge Sorted Array
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_88
 Notes:
 Given two sorted integer arrays A and B, merge B into A as one sorted array.
 Note:
 You may assume that A has enough space to hold additional elements from B. 
 The number of elements initialized in A and B are m and n respectively.
 Solution: From back to forth.
 */

class Solution1 {
public:
    void merge(int A[], int m, int B[], int n) {
        int i = m - 1;
        int j = n - 1;
        int x = m + n - 1;
        while (i >= 0 && j >= 0)
            if (A[i] >= B[j]) A[x--] = A[i--];
            else A[x--] = B[j--];
        while (j >= 0) A[x--] = B[j--];
    }
};


解法二：
新建C数组保存A数组所有内容，然后从前往后通过B，C数组元素比较，依次得出A数组排序序列。
时间复杂度： O（m+n）；           空间复杂度：O（m）；
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int C[m];
        int i = 0, j = 0,index = 0;
       
// i对应C数组下标，j对应B数组下标，index为结果A下标     
        memcpy(C, A, sizeof(int) * m);
        for(index = 0;i < m && j < n; index++){
            if (C[i] <= B[j]){
                A[index] = C[i];
                i++;
            } else {
                A[index] = B[j];
                j++;
            }
        }
        if(i < m) for( ; i < m;i++ ){
            A[index] = C[i];
            index++;
        }
        if(j < n) for( ; j < n; j++ ){
            A[index] = B[j];
            index++;
        }
    }
};

