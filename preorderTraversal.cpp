

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
void preorderTraversalHelper(struct TreeNode* root,int *arr,int* returnSize){
	if(root==NULL){
		return ;
	}
	arr[*returnSize]=root->val;
	(*returnSize)++;
	preorderTraversalHelper(root->left,arr,returnSize);
	preorderTraversalHelper(root->right,arr,returnSize);	
}
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
	int *res=(int *)malloc(N*sizeof(int));
	if(res==NULL){
		exit(EXIT_FAILURE);
	}
	*returnSize=0;
    preorderTraversalHelper(root,res,returnSize);
    return res;
}
