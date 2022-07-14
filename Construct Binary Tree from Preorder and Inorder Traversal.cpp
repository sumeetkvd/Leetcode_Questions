


The solution in CPP: -


class Solution {
public:
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        unordered_map<int, int> pos;
        int n = pre.size();
        for (int i = 0; i < n; i++) {
            pos[in[i]] = i;
        }
        TreeNode* root = NULL;
        for (int i = 0; i < n; i++) {
            int num = pre[i], p = pos[num];
            TreeNode* tr = new TreeNode(num);
            if (i == 0) {
                root = tr;
                continue;
            }
            TreeNode* node = root, *prev = NULL;
            while (node) {
                prev = node;
                if (pos[node->val] > p) node = node->left;
                else  node = node->right;
            }
            node = tr;
            if (pos[prev->val] > p) prev->left = tr;
            else    prev->right = tr;
        }
        return root;
    }
};


