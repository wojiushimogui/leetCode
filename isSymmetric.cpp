
 struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
  };
 
/*
˼·��������������ڵ��ֵ�����������ҽڵ��ֵ���бȽϣ��������������ҽڵ��ֵ������������ڵ��ֵ���бȽ�
*/
bool isSym(struct TreeNode* leftroot,struct TreeNode* rightroot){
	if(leftroot==NULL&&rightroot==NULL){
        return true;
    }
    return (leftroot->val==rightroot->val)&&isSym(leftroot->left,rightroot->right)&&isSym(leftroot->right,rightroot->left);
}
bool isSymmetric(struct TreeNode* root) {
    return isSym(root,root) ; 
}
