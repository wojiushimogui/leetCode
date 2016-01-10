#include<stdio.h>
#include<stdlib.h>
//统计1~n中组成的唯一二叉搜索树的个数 
//二叉搜索树的特性为：如果左子树不为空，则左子树节点的值全部小于根节点，如果右子树不为空，则右子树全部大于根节点的值
//参考地址：https://leetcode.com/discuss/75282/easy-to-understand-top-down-dp-solution 
/*
For a valid BST, there must be a node that is the root. The root can be any number between 1 and n. What if the root is k where k is in between 1 and n? It becomes obvious that 1 to k-1 should be k's left children and k+1 to n should be k's right children. Thus, a recursive formula is formulated as follows:

result of BSTs with k being the root 
= count of BSTs of k-1 consecutive numbers * count of BSTs of n-k consecutive numbers
And since we have a total of n choices for k, total number of BSTs is thus a sum of all n choices for k.
*/ 
int numTreeWhenRootCountEqualN(int n,int *resCountwhenRootValue_N){
	if(n<=1){
		return 1;
	}
	if(resCountwhenRootValue_N[n-1]>0){
		return resCountwhenRootValue_N[n-1];
	}
	int totalCount=0;
	for(int i=1;i<=n;i++){//统计当根节点为1~n时的二叉搜索树的个数 
		// numTreeWhenRootCountEqualN(i-1,resCountwhenRootValue_N)为当根节点为i时，符合条件的左子树的个数
		// numTreeWhenRootCountEqualN(n-i,resCountwhenRootValue_N)当根节点为i时，符合条件的右子树的个数
		totalCount+=numTreeWhenRootCountEqualN(i-1,resCountwhenRootValue_N)*numTreeWhenRootCountEqualN(n-i,resCountwhenRootValue_N);		
	}
	resCountwhenRootValue_N[n-1]=totalCount;//保存复用 
	return totalCount; 
}
int numTrees(int n) {
	if(n<1) return 0;
	//开辟一段空间，来保存结果，该数组 resCountwhenRootValue_N[k]中保存着的是根节点的数值为 k-1时满足条件的二叉搜索树的个数 
    int *resCountwhenRootValue_N=(int *)malloc(n*sizeof(int));
	if(resCountwhenRootValue_N==NULL){
		exit(EXIT_FAILURE);
	} 
	//初始化为零
	memset(resCountwhenRootValue_N,0,n*sizeof(int));
	return numTreeWhenRootCountEqualN(n,resCountwhenRootValue_N); 
}
