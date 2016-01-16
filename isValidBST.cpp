/**
 * Definition for a binary tree node.*/
  struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
  };
 
//利用递归求解即可
bool isValidBST_v1(struct TreeNode* root,int low,int high){
	if(root==NULL){
    	return true;
	}
	return (low<root->val)&&(root->val<high)&&(isValidBST_v1(root->left,low,root->val))&&(isValidBST_v1(root->right,root->val,high))
}
bool isValidBST(struct TreeNode* root) {
	return isValidBST_v1(root,INT_MIN,INT_MAX);	
}
/*
思路来源于：https://leetcode.com/discuss/74359/4-line-c-simple-solution-easy-understanding 
bool isValidBST(TreeNode* root) {
    return dfs_valid(root, LONG_MIN, LONG_MAX);
}
bool dfs_valid(TreeNode *root, long low, long high) {
    if (!root) return true;
    return low < root->val && root->val < high && dfs_valid(root->left, low, root->val)
            && dfs_valid(root->right, root->val, high);
}
*/
