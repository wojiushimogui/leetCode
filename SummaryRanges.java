package com.wrh.leetcode;

import java.util.ArrayList;
import java.util.List;

public class SummaryRanges {

	public static void main(String[] args) {
		int[] nums = {0,1,2,4,5,7};
		List<String> res =new SummaryRanges().summaryRanges(nums);
		for(String str:res){
			System.out.print(str +";");
		}
	}
	
	public List<String> summaryRanges(int[] nums) {
        //将不连续的数字保存到一个List中即可		
		List<String> res = new ArrayList<String> ();
		if(nums==null||nums.length<=0){
			return res;
		}
		if(nums.length ==1){//要考虑长度为1这种情况
			res.add(nums[0]+"");
			return res;
		}
		//下面就是nums长度大于1的情况，找出不连续的每段数据
		int begin=nums[0];
		int end = 0;
		for(int i=1;i<nums.length;i++){
			int cur = nums[i-1];
			end = nums[i];
			if(end!=cur+1){//此时 i-1 和 i 就是不连续的点
				
				if(begin==cur){
					res.add(begin+"");
				}
				else{
					res.add(begin+"->"+cur);
				}
				
				begin = end;
			}	
			
			//将最后一组加入
			if(i == nums.length-1){
				if(begin==end){
					res.add(begin+"");
				}
				else{
					res.add(begin+"->"+end);
				}
			}
		}		
		return res;		
    }

}
