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
	public List<List<Integer>> subsets(int[] nums) {
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
        //����һ��List��������
        List<List<Integer>> resultList=new ArrayList<List<Integer>>();
        
        resultList.add(new ArrayList<Integer>());//���ռ�����
		while(increment(arr)){//ģ������Ƽ�һ
			List<Integer> list=new ArrayList<Integer>();//
			for(int i=0;i<len;i++){				
				if(arr[i]==1){//arr�б�־λ1ʱ��nums����ӦԪ�ز��������
					list.add(nums[i]);	
				}
			}			
			resultList.add(list);
		}
		
		return resultList;
    }

}
