	package com.wrh.leetcode;
	
	import java.util.ArrayList;
	import java.util.List;
	
	public class BinaryTreePaths {
		
		public List<String> binaryTreePaths(TreeNode root) {
			 
			 List<List<Integer>> res = binaryTreePathHelper(root);
			 
			 List<String> paths = new ArrayList<String> ();
			 for(List<Integer> list : res){
				 StringBuilder sb = new StringBuilder();
				 for(int i=0;i<list.size();i++){
					 if(i==list.size()-1){
						 sb.append(list.get(i));
					 }
					 else{
						 sb.append(list.get(i)).append("->");
					 }
				 }
				 paths.add(sb.toString());
				 
			 }
			 
			 return paths;
		
	    }
	
		private List<List<Integer>> binaryTreePathHelper(TreeNode root) {	
			
			List<List<Integer>> res = new ArrayList<List<Integer>>() ;
			if(root==null){
				return res;
			}
			if(root.left==null&&root.right==null){//р╤вс╫з╣Ц
				List<Integer> list = new ArrayList<Integer>();
				list.add(root.val);
				res.add(list);
				return res;
			}
			else {
				List<List<Integer>> leftRes = binaryTreePathHelper(root.left) ;
				List<List<Integer>> rightRes = binaryTreePathHelper(root.right) ;
				for(List<Integer> list : leftRes){
					list.add(0,root.val);
					res.add(list);
				}
				for(List<Integer> list : rightRes){
					list.add(0,root.val);
					res.add(list);
				}
				return res;
				
			}
		}
		
		public static void main(String[] args){
			TreeNode t = new TreeNode(3);
			TreeNode t2 = new TreeNode(5);
			TreeNode t3 = new TreeNode(6);
			t.left = t2 ;
			t.right = t3 ;
			
			List<String> list = new BinaryTreePaths().binaryTreePaths(t);
			for(String str:list){
				System.out.println(str);
			}
		}
	}
