package com.wrh.leetcode;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class Rob_v1 {
	//https://leetcode.com/discuss/95367/1ms-java-solution
	public int rob(TreeNode root) {
		int []maxValue=robHelper(root);
		return Math.max(maxValue[0], maxValue[1]);
    }
	/*
	 * 返回的数组长度为2，第一个存储的是
	 * */
	private int[] robHelper(TreeNode root) {
		if(root==null){
			return new int[]{0,0};
		}
		//maxValue[0]用来存储根节点没有参与的最大值，而maxValue[1]则是存储这根节点参与了产生的最大值。
		int[] maxValue=new int[2];
		int[] leftMaxValue=robHelper(root.left);
		int[] rightMaxValue=robHelper(root.right);
		maxValue[0]=Math.max(leftMaxValue[1], leftMaxValue[0])+Math.max(rightMaxValue[1], rightMaxValue[0]);
		maxValue[1]=root.val+leftMaxValue[0]+rightMaxValue[0];//既然root参与了，则root的左右节点就不能参与了。
		return maxValue;
	}
}
