package com.wrh.leetcode;


public class HIndex3 {
	
	//
    public int hIndex(int[] citations) {
    	if(citations==null||citations.length==0){
    		return 0;
    	}
    	int len = citations.length;
    	int[] tempArr =new int[len+1];
    	for(int i=0;i<len;i++){
    		if(citations[i]>=len){
    			tempArr[len]++;
    		}
    		else{
    			tempArr[citations[i]]++;
    		}
    	}
    	int index = len;
    	int totalNum = 0;
    	while(index>=0){
    		totalNum+=tempArr[index];
    		if(totalNum>=index){
    			break;
    		}
    		index--;
    		
    	}
    	return index;
    }
    
    public int hIndex2(int[] citations) {
    	if(citations==null||citations.length==0){
    		return 0;
    	}
    	int left = 0;
    	int len = citations.length;
    	int right = len-1;
    	int mid = 0;
    	while(left<=right){
    		mid = left+(right-left)/2;
    		if(citations[mid]==len-mid){
    			return citations[mid];
    		}
    		else if(citations[mid]<len-mid){//�������࣬���Ƿ񻹴��ڸ���Ľ��
    			left = mid+1;
    		}
    		else if(citations[mid]>len-mid){//�������٣����Ƿ���ڸ���������������õĽ��
    			right = mid -1;
    		}
    	}
    	return len -(right+1);  //�±�right+1�ұߵ�ȫ�� citations[i]>	len -(right+1)
    }
}
