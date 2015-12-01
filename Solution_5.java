package com.wrh.leetcode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Solution_5 {

	public static void main(String[] args) {
		Solution_5 s=new Solution_5();
		int nums[]={1,2,3};
		List<List<Integer>> l=s.subsets(nums);
		for(List<Integer> list:l){
			for(int i=0;i<list.size();i++){
				System.out.print(list.get(i)+"  ");
			}
			System.out.println("输出一个组合结束");
		}
	}
	//模拟二进制加1
	public boolean increment(int []arr){
		int len=arr.length;
		arr[len-1]++;//最低位加1
		for(int i=len-1;i>=0;i--){
			if(arr[i]>=2){
				if(i==0){//最高位产生了进位，则已经变为了全一，结束
					return false;					
				}
				else{//
					arr[i]-=2;
					arr[i-1]++;
				}
			}
		}
		return true;
	}
	public List<List<Integer>> subsets(int[] nums) {
        if(nums==null||nums.length<1){
        	return null;
        }
        //先进行排序
        Arrays.sort(nums);
        //开辟一个与nums长度相同的标志数组,并初始化为零
        int len=nums.length;
        int arr[]=new int[len];
        for(int i=0;i<len;i++){
        	arr[i]=0;
        }
        //定义一个List来保存结果
        List<List<Integer>> resultList=new ArrayList<List<Integer>>();
        
        resultList.add(new ArrayList<Integer>());//将空集加入
		while(increment(arr)){//模拟二进制加一
			List<Integer> list=new ArrayList<Integer>();//
			for(int i=0;i<len;i++){				
				if(arr[i]==1){//arr中标志位1时，nums的相应元素参与了组合
					list.add(nums[i]);	
				}
			}			
			resultList.add(list);
		}
		
		return resultList;
    }

}
