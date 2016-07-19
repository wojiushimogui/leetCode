package com.wrh.leetcode;

import java.util.LinkedList;
import java.util.Queue;

public class Codec {
    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
    	StringBuffer res = new StringBuffer();
    	if(root==null){
    		return res.toString();
    	}
        //������������������ȡ���ڵ㣬�����ַ���
    	Queue<TreeNode> q = new LinkedList<TreeNode>();
    	Queue<TreeNode> q2 = new LinkedList<TreeNode>();
    	q.add(root);
    	res.append("[").append(root.val);
    	while(!q.isEmpty()){
    		while(!q.isEmpty()){
    			TreeNode node = q.poll();
    			if(node!=null){
    				q2.add(node.left);
    				q2.add(node.right);
    			}	
    		}
    		StringBuffer str = new StringBuffer();
    		while(!q2.isEmpty()){
    			TreeNode node = q2.poll();
    			if(node!=null){
    				str.append(",").append(node.val);
    				q.add(node);
    			}
    			else{
    				str.append(",").append("null");
    			}
    		}
    		res.append(str);
    	}
    	res.append("]");
    	
    	return res.toString();
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {  	
        int dataLen = data.length();
        if(dataLen<=2){
        	return null;
        }
        String[] vals = data.substring(1, dataLen-1).split(",");//ȥ���ַ����������ߵ����Ų����ݷֺŽ����ݷֿ�
        
        int len = vals.length;
        if(len==0){
        	return null;
        }
        TreeNode[]  treeNodes = new TreeNode[len];
        //������¼�ڵ��ǵڼ����ǿս��,���㿪ʼ
        int[] counts = new int[len];
        counts[0]=0;
        treeNodes[0] = new TreeNode(Integer.valueOf(vals[0]));
        for(int i=1;i<len;i++){
        	if(vals[i].equals("null")){
        		treeNodes[i]=null;
        		counts[i]=counts[i-1];
        	}
        	else{
        		treeNodes[i]=new TreeNode(Integer.valueOf(vals[i]));
        		
        		counts[i]=counts[i-1]+1;
        	}
        }
        
        for(int i=0;i<len&&2*counts[i]+1<len;i++){
        	if(treeNodes[i]!=null){
        		treeNodes[i].left = treeNodes[2*counts[i]+1];
        		if(2*counts[i]+2<len){//���ǿ������һ���ڵ�ֻ����������û��������
        			treeNodes[i].right = treeNodes[2*counts[i]+2];
        		}
        		
        	}
        }
        return treeNodes[0];
    }  
    
    public static void main(String[] args){
    	Codec c = new Codec();
    	String str = "[1,2,3]";
    	TreeNode root =c.deserialize(str);
    	String res = c.serialize(root);
    	System.out.println(res);
    }
}
