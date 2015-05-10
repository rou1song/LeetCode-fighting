/*
 Problem:    Longest Consecutive Sequence
 Difficulty: Hard
 Source:     https://oj.leetcode.com/problems/longest-consecutive-sequence/
 Notes:
 Given an unsorted array of integers, find the length of the longest consecutive 
 elements sequence.
 For example,
 Given [100, 4, 200, 1, 3, 2],
 The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.
 Your algorithm should run in O(n) complexity.
 Solution 1: Update solution. This solution is from Peking2 (http://blog.sina.com.cn/s/blog_b9285de20101iqar.html).
             This solution is much easier to understand.
 Solution 2: by Yao Liu.
*/
//暴力做法：复杂度O（nlogn），先排序，后做。
class Solution1 {
public:
    static bool cmp(int a, int b) {
        return a < b;
    }
    int longestConsecutive(vector<int>& nums) {
        int count = 1;
        int maxCount = 0;
        if(nums.size() == 1) return 1;
        
        sort(nums.begin(), nums.end(), cmp);

        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == nums[i-1] + 1) {
                count++;
            } else if(nums[i] == nums[i-1]) {
                continue;
            } else {
                maxCount = max(count, maxCount);
                count = 1;
            } 
        }
        maxCount = max(count, maxCount);      //一定要加，否则最后一段连续的数长度考虑不进去
        return maxCount;
    }
};
//O(n) ,使用set来做，每次把当前数相连的数全部删除并求得upper，lower。 赞！！！
class Solution2 {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_set<int> s;
        int res = 0;
        for (int i = 0; i < num.size(); ++i)        //或：unordered_set<int> s(num.begin(), num.end());
            s.insert(num[i]);
        for (int i = 0; i < num.size(); ++i) {
            if (s.find(num[i]) == s.end())
                continue;
            int upper = num[i], lower = num[i];
            while (s.find(upper+1) != s.end())  s.erase(++upper);     //删除元素，保证不做重复操作，O（n）
            while (s.find(lower-1) != s.end())  s.erase(--lower);
            if (upper != lower)
                s.erase(num[i]);
            res = max(res, upper - lower + 1);
        }
        return res;
    }
}

//代码最简：利用map的原理： val如果没在map中出现过，则 m[val] = 0；
/* use a hash map to store boundary information of consecutive sequence for each element;  4 cases when a new element i reached:
    1) neither i+1 nor i-1 has been seen: m[i]=1;
    2) both i+1 and i-1 have been seen: extend m[i+m[i+1]] and m[i-m[i-1]] to each other;
    3) only i+1 has been seen: extend m[i+m[i+1]] and m[i] to each other;
    4) only i-1 has been seen: extend m[i-m[i-1]] and m[i] to each other.
*/
class Solution3 {
public:
    int longestConsecutive(vector<int>& num) {
        unordered_map<int, int> m;
        int res = 0;
        int val;
        for (int k = 0; k < num.size(); k++) {
            val = num[k];
            if (m[val]) continue;             //如果val之前出现过，
            res = max(r, m[val] = m[val + m[val + 1]] = m[val - m[val - 1]] = m[val + 1] + m[val - 1] + 1); 
            //更新每一段的left和right端点值，值都是本段的长度，而段中间元素的value值就不care了
        }
        return res;
    }
};

//第三种解法的多条件判断版本
class Solution4 {
public:
     int longestConsecutive(vector<int> &num) {
        int longest = 0;
        unordered_map<int, int> table;
        for(int i = 0, count = num.size(); i < count; ++i) 
            if(table.find(num[i]) == table.end()) {
                int val = num[i], update;
                if(table.find(val - 1) != table.end() && table.find(val + 1) != table.end())
                    // assigning to table[val] here is only for adding val as a key of the hashtable.
                    update = table[val] = 
                             table[val - table[val - 1]] = 
                             table[val + table[val + 1]] = 
                             table[val - 1] + table[val + 1] + 1; 
                else if(table.find(val - 1) != table.end())
                    update = table[val] = ++table[val - table[val - 1]];
                else if(table.find(val + 1) != table.end())
                    update = table[val] = ++table[val + table[val + 1]];
                else 
                    update = table[val] = 1;
                longest = max(longest, update);
            }
        return longest;
    }
};
