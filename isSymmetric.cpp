
 struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
  };
 
/*
思路：将左子树的左节点的值与右子树的右节点的值进行比较，而将左子树的右节点的值与右子树的左节点的值进行比较
*/
bool isSym(struct TreeNode* leftroot,struct TreeNode* rightroot){
	if(leftroot==NULL&&rightroot==NULL){
        return true;
    }
    else if(leftroot==NULL&&rightroot!=NULL||(leftroot!=NULL&&rightroot==NULL)) {
    	return false;
	}
    
    return (leftroot->val==rightroot->val)&&isSym(leftroot->left,rightroot->right)&&isSym(leftroot->right,rightroot->left);
}
bool isSymmetric(struct TreeNode* root) {
    return isSym(root,root) ; 
}
