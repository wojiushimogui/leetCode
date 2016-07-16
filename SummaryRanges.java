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
        //�������������ֱ��浽һ��List�м���		
		List<String> res = new ArrayList<String> ();
		if(nums==null||nums.length<=0){
			return res;
		}
		if(nums.length ==1){//Ҫ���ǳ���Ϊ1�������
			res.add(nums[0]+"");
			return res;
		}
		//�������nums���ȴ���1��������ҳ���������ÿ������
		int begin=nums[0];
		int end = 0;
		for(int i=1;i<nums.length;i++){
			int cur = nums[i-1];
			end = nums[i];
			if(end!=cur+1){//��ʱ i-1 �� i ���ǲ������ĵ�
				
				if(begin==cur){
					res.add(begin+"");
				}
				else{
					res.add(begin+"->"+cur);
				}
				
				begin = end;
			}	
			
			//�����һ�����
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
