class Solution {
public:
    int ans = 0;
    
    pair<int,int> dfs(TreeNode* root) {
        if (!root) return {0,0};
        
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        
        int sum = left.first + right.first + root->val;
        int cnt = left.second + right.second + 1;
        
        if (root->val == sum / cnt) ans++;
        
        return {sum, cnt};
    }
    
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
