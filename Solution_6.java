package com.wrh.leetcode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class Solution_6 {

	public static void main(String[] args) {
		Solution_6 s=new Solution_6();
		int nums[]={1,2,2};
		List<List<Integer>> l=s.subsetsWithDup(nums);
		for(List<Integer> list:l){
			for(int i=0;i<list.size();i++){
				System.out.print(list.get(i)+"  ");
			}
			System.out.println("���һ����Ͻ���");
		}
	}
	//ģ������Ƽ�1
		public boolean increment(int []arr){
			int len=arr.length;
			arr[len-1]++;//���λ��1
			for(int i=len-1;i>=0;i--){
				if(arr[i]>=2){
					if(i==0){//���λ�����˽�λ�����Ѿ���Ϊ��ȫһ������
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
	//nums�����ظ�������
	public List<List<Integer>> subsetsWithDup(int[] nums) {
		if(nums==null||nums.length<1){
        	return null;
        }
        //�Ƚ�������
        Arrays.sort(nums);
        //����һ����nums������ͬ�ı�־����,����ʼ��Ϊ��
        int len=nums.length;
        int arr[]=new int[len];
        for(int i=0;i<len;i++){
        	arr[i]=0;
        }
        Set<List<Integer>> s=new HashSet<List<Integer>>();
        //����һ��List��������
        List<List<Integer>> resultList=new ArrayList<List<Integer>>();
        s.add(new ArrayList<Integer>());
        //resultList.add(new ArrayList<Integer>());//���ռ�����
		while(increment(arr)){//ģ������Ƽ�һ
			List<Integer> list=new ArrayList<Integer>();//
			for(int i=0;i<len;i++){				
				if(arr[i]==1){//arr�б�־λ1ʱ��nums����ӦԪ�ز��������
					list.add(nums[i]);	
				}
			}
			s.add(list);
			//resultList.add(list);
		}
		for(List<Integer> l:s){
			resultList.add(l);
		}		
		return resultList;
    }

}
