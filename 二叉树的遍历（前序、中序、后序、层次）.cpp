
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode *> st;
        TreeNode *cur = root;
        while (cur || !st.empty()) {
            if (cur) {
                res.push_back(cur->val);
                st.push(cur);
                cur = cur->left;
            } else if (!st.empty()) {
                cur = st.top()->right;
                st.pop();
            }
        }
        return res;
    }

    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode *> st;
        TreeNode *cur = root;
        while (cur || !st.empty()) {
            if (cur) {
                st.push(cur);
                cur = cur->left;
            } else if (!st.empty()) {
                res.push_back(st.top()->val);
                cur = st.top()->right;
                st.pop();
            }
        }
        return res;
    }
    
    vector<int> postorderTraversal_1(TreeNode *root) {
        vector<int> res;
        stack<TreeNode *> st;
        TreeNode *last = NULL, *cur = root;
        while(cur || !st.empty()){
            if (cur) {
                st.push(cur);
                cur = cur->left;
            } else {
                TreeNode *peak = st.top();
                if(peak->right && last != peak->right)
                    cur = peak->right;
                else {
                    res.push_back(peak->val); 
                    st.pop();
                    last = peak;
                }
            }
        }
        return res;
    }
    
    //不需要写成二维vector输出的后序遍历：
    void levelOrder(TreeNode* root) {
        queue<TreeNode* > qu;
        TreeNode* tmp = NULL;
        if(root) 
            qu.push(root);
        while(!qu.empty()) {
                tmp = qu.front();
                cout<< tmp.val <<endl;  //访问当前队首节点
                if(tmp->left) 
                    qu.push(tmp->left);
                if(tmp->right) 
                    qu.push(tmp->right);
                qu.pop();
        }
    }
    
     //写成二维vector输出的后序遍历：
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > ans;
        vector<int> level;
        queue<TreeNode* > qu;
        TreeNode* tmp = NULL;
        int levelNum;
        if(root) qu.push(root);
        
        while(!qu.empty()) {
            levelNum = qu.size();
            for(int i = 0; i < levelNum; i++) {
                tmp = qu.front();
                level.push_back(tmp->val);
                if(tmp->left) qu.push(tmp->left);
                if(tmp->right) qu.push(tmp->right);
                qu.pop();
            }
            ans.push_back(level);
            level.clear();
        }
        return ans;
    }
    
