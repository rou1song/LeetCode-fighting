/*
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.
*/
// map , 保证一对一映射，所以必须2个map
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;
        if(s.empty() && t.empty()) return true;
        unordered_map<char, char> hmap, rmap;
        
        for(int i = 0; i < s.size(); i++) {
            if(hmap.find(s[i]) != hmap.end() && t[i] != hmap[s[i]]) {
                return false;
             else 
                hmap.insert(make_pair(s[i], t[i]));
                
            if(rmap.find(t[i]) != rmap.end() && s[i] != rmap[t[i]]) 
                return false;
             else 
                rmap.insert(make_pair(t[i], s[i]));
        }
        return true;
    }
};
//字符，128个，对应保存的是在string中的位置，检测s[i], t[i]上次存储的位置是否相同，不同则对应关系就有不对。
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;
        int m1[128] = {0}, m2[128] = {0}, n = s.size();
        for (int i = 0; i < n; ++i) {
            if (m1[s[i]] != m2[t[i]]) return false;
            m1[s[i]] = i + 1;
            m2[t[i]] = i + 1;
        }
        return true;
    }
};
