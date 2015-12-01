package com.wrh.leetcode;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Solution_7 {

	public static void main(String[] args) {
		Solution_7 s=new Solution_7();
		//int nums[]={1,2,2};
		int k=1;
		int n=1;
		List<List<Integer>> l=s.combine(n,k);
		for(List<Integer> list:l){
			for(int i=0;i<list.size();i++){
				System.out.print(list.get(i)+"  ");
			}
			System.out.println("输出一个组合结束");
		}
	}
	boolean increment(int[] arr){
		if(arr==null||arr.length<1){
			return false;
		}
		int len=arr.length;
		arr[len-1]++;
		for(int i=len-1;i>=0;i--){
			if(arr[i]>=2){
				if(i==0){
					return false;
				}
				else{
					arr[i]-=2;
					arr[i-1]++;
				}
			}
		}
		
		return true;
	}
    public List<List<Integer>> combine(int n, int k) {
    	if(n<1||k<1){
    		return null;
    	}
    	Map<Integer,List<List<Integer>>> map=new HashMap<Integer,List<List<Integer>>>();
    	//开辟一个长度为n的标志数组，并初始化为零
    	int arr[]=new int[n];
    	for(int i=0;i<n;i++){
    		arr[i]=0;
    	}
    	int arrNum[]=new int[n];
    	for(int i=0;i<n;i++){
    		arrNum[i]=i+1;
    	}
    	while(increment(arr)){
    		List<Integer> list=new ArrayList<Integer>();
    		for(int i=0;i<n;i++){
    			if(arr[i]==1){
    				list.add(arrNum[i]);
    			}
    		}
    		int size=list.size();
    		List<List<Integer>> l=map.getOrDefault(size, new ArrayList<List<Integer>> ());
    		l.add(list);
    		map.put(size, l);
    	}
    	return map.get(k);
	}

}
