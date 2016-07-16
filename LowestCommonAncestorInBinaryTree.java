package com.wrh.leetcode;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class LowestCommonAncestorInBinaryTree {
	
	private Map<List<TreeNode>,Boolean> map = new HashMap<List<TreeNode>,Boolean>();
	
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if(root==null||p==null||q==null){
        	return null;
        }
        boolean isCanArrivePQNode = isArrive(root,p,q);     
        
        boolean isCanArriveForLeftNode = isArrive(root.left, p, q);
        boolean isCanArriveForRightNode= isArrive(root.right, p, q);
       
        if(isCanArrivePQNode&&!isCanArriveForLeftNode&&!isCanArriveForRightNode){
        	return root;
        }
        else if(isCanArriveForLeftNode){
        	return lowestCommonAncestor(root.left, p, q);
        }
        else if(isCanArriveForRightNode){
        	return lowestCommonAncestor(root.right, p, q);
        }
        else{
        	return null;
        }
        
    }

	private boolean isArrive(TreeNode root, TreeNode p, TreeNode q) {
		boolean isCanArrivePNode = isArrive(root,p);
		
        boolean isCanArriveQNode = isArrive(root,q);
		return isCanArrivePNode&&isCanArriveQNode;
	}

	private boolean isArrive(TreeNode root, TreeNode p) {
		if(root==null||p==null){
			return false;
		}
		//���ж���map���Ƿ����root�ڵ�ͽڵ�p�Ƿ�ɵ������
		List<TreeNode> l = new ArrayList<TreeNode> ();
		l.add(root);
		l.add(p);
		//�Ȳ鿴�Ƿ���key
		if(map.containsKey(l)){
			return map.get(l);
		}
		else{
			if(root==p){
				return true;
			}
			else{
				boolean isCanArrivePNode = isArrive(root.left,p);
				//������
				List<TreeNode> list = new ArrayList<TreeNode>();
				list.add(root.left);
				list.add(p);
				map.put(list, isCanArrivePNode);
				boolean isCanArriveQNode = isArrive(root.right,p);
				//������
				List<TreeNode> list2 = new ArrayList<TreeNode>();
				list2.add(root.right);
				list2.add(p);
				map.put(list2, isCanArriveQNode);
				return isCanArrivePNode||isCanArriveQNode;
			}
			
		}
			
	}
}
