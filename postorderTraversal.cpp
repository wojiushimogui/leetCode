/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
void postorderTraversalHelper(struct TreeNode* root,int *res,int *returnSize){
	if(root==NULL){
		return;
	}
	postorderTraversalHelper(root->left,res,returnSize);
	postorderTraversalHelper(root->right,res,returnSize);
	res[(*returnSize)]=root->val;
	(*returnSize)++;
}
#define N 1000
int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    int *res=(int *)malloc(N*sizeof(int));
    if(res==NULL){
    	exit(EXIT_FAILURE);
	}
	(*returnSize)=0;
	postorderTraversalHelper(root,res,returnSize);
	return res;
	
}
