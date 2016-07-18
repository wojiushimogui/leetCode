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
    		else if(citations[mid]<len-mid){//次数过多，看是否还存在更大的结果
    			left = mid+1;
    		}
    		else if(citations[mid]>len-mid){//次数过少，看是否存在跟多次数的其它更好的结果
    			right = mid -1;
    		}
    	}
    	return len -(right+1);  //下标right+1右边的全部 citations[i]>	len -(right+1)
    }
}
