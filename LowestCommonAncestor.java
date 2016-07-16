package com.wrh.leetcode;

public class LowestCommonAncestor {
	
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if(root==null||p==null||q==null){
        	return null;
        }
        if(p.val<=root.val&&root.val<=q.val||(q.val<=root.val&&root.val<=p.val)){
        	return root;
        }
        else if(p.val<root.val&&p.val<root.val){
        	return lowestCommonAncestor(root.left,p,q);
        }
        else/* if(p.val>root.val&&q.val>root.val)*/{
        	return lowestCommonAncestor(root.right,p,q);
        }
        
    }
}
