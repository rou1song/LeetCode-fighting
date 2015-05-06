/*
 Problem:    Two Sum
 Difficulty: Medium
 Source:     http://oj.leetcode.com/problems/two-sum/
 Notes:
 Given an array of integers, find two numbers such that they add up to a specific target number.
 The function twoSum should return indices of the two numbers such that they add up to the target, 
 where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
 You may assume that each input would have exactly one solution.
 Input: numbers={2, 7, 11, 15}, target=9
 Output: index1=1, index2=2
 Solution: 1. Sort first. O(nlgn)
           2. Hash table. O(n)
           
 Note:  Hash Table solution has been updated.  In case that the two elements are the same, 
        all the indices should be stored in the map.
 */
 
 class Solution1 {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> res;
        map <int,int> hmap;
        map <int,int>::iterator iter;
        
        for(int i = 0; i < numbers.size(); i++){
            int sub = target - numbers[i];
            if (hmap.find(sub) == hmap.end()) {
                hmap[numbers[i]] = i+1;
            } else {
                res.push_back(hmap[target - numbers[i]]);
                res.push_back(i+1);
                break;
            }
        }
        return res;
    }
};



class Solution2 {
public:
    bool cmp(pair<int,int> a,pair<int,int> b){
        return a.first < b.first;
    }

    void swap(int &a,int &b){
        int tmp = a;
        a = b;
        b = tmp;
    }
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> res;
        vector< pair<int,int> > num;
        
        for(int i = 0; i < numbers.size(); i++)
            num.push_back(make_pair(numbers[i],i+1));
        
        sort(num.begin(),num.end(),cmp);
        
        vector< pair<int,int> >::iterator beg = num.begin();
        vector< pair<int,int> >::iterator end = num.end() - 1;
        
        while(beg != end) {
            if(beg->first + end->first == target) {
                res.push_back(beg->second);
                res.push_back(end->second);
                break;
            } else if (beg->first + end->first < target) {
                beg++;
            } else {
                end--;
            }
        }
        if(res[0] > res[1])
            swap(res[0],res[1]);

        return res;
    }
};
