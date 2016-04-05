

/**
 * Definition for a binary tree node.*/
  struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
  };
void invertTreeHelper(struct TreeNode* root){
	if(root==NULL){
		return;
	}
	if(root->left!=NULL||root->right!=NULL){
		struct TreeNode * tempNode=root->left;
		root->left=root->right;
		root->right=tempNode;
		invertTreeHelper(root->left);
		invertTreeHelper(root->right);
	}
}
struct TreeNode* invertTree(struct TreeNode* root) {
    invertTreeHelper(root);
    return root;
}
