 int dfs(struct TreeNode* node){
    if(node == NULL){
        return 0;
    }
    int ans = 0;
    struct TreeNode* left = node -> left;
    if(left && left -> left == NULL && left -> right == NULL){
        ans += left -> val;
    }
    ans += dfs(node -> left);
    ans += dfs(node -> right);
    return ans;
}
int sumOfLeftLeaves(struct TreeNode* root) {
    return dfs(root);
}