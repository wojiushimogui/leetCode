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
	 * ���ص����鳤��Ϊ2����һ���洢����
	 * */
	private int[] robHelper(TreeNode root) {
		if(root==null){
			return new int[]{0,0};
		}
		//maxValue[0]�����洢���ڵ�û�в�������ֵ����maxValue[1]���Ǵ洢����ڵ�����˲��������ֵ��
		int[] maxValue=new int[2];
		int[] leftMaxValue=robHelper(root.left);
		int[] rightMaxValue=robHelper(root.right);
		maxValue[0]=Math.max(leftMaxValue[1], leftMaxValue[0])+Math.max(rightMaxValue[1], rightMaxValue[0]);
		maxValue[1]=root.val+leftMaxValue[0]+rightMaxValue[0];//��Ȼroot�����ˣ���root�����ҽڵ�Ͳ��ܲ����ˡ�
		return maxValue;
	}
}
