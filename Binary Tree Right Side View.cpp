Binary Tree Right Side View: -


The solution in CPP: -


class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> p, q;
        vector<int> res;
        if (!root) return res;
        
        p.push(root);
        while (1){
            int last;
            while (!p.empty()){
                TreeNode* cur = p.front();
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
                last = cur->val;
                p.pop();
            }
            res.push_back(last);
            p=q;
            while (!q.empty()){q.pop();}
            if (p.empty()) return res;
        }
    }
};

