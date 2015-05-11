/*
 Problem:    Same Tree
 Difficulty: easy
 Source:     http://leetcode.com/onlinejudge#question_100
 Notes:
 Given two binary trees, write a function to check if they are equal or not.
 Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
 Solution: recursion.
 */
 
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) 
            return true;
        else if(p == NULL || q == NULL)
                return false;
        if(p->val != q->val) 
            return false;
            
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
