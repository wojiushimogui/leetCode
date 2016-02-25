  struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
  };
/*
˼·����һ��ڵ�����Ϊ�ӽ�����+1 
*/
int  maxDepth1(struct TreeNode* root){
	if(root==NULL){
		return 0;
	}
	int leftMaxDepth=maxDepth1(root->left);
	int rightMaxDepth=maxDepth1(root->right);	
	return (leftMaxDepth>rightMaxDepth?leftMaxDepth:rightMaxDepth)+1;
}
int maxDepth(struct TreeNode* root) {
    //int depthTree=0;
	return maxDepth1(root); 
}
