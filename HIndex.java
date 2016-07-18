package com.wrh.leetcode;


public class HIndex {
	
	//在N篇paper中至少有h篇论文大于h，则才返回h。N篇paper最大值返回N
    public int hIndex(int[] citations) {
    	if(citations==null||citations.length==0){
    		return 0;
    	}
    	int len = citations.length;
    	int[] tempArr = new int[len+1]; 
    	for(int i=0;i<len;i++){
    		if(citations[i]>=len){
    			tempArr[len]++;
    		}
    		else{
    			tempArr[citations[i]]++;
    		}
    	}
    	int totalNum = 0;
    	for(int i=len;i>=0;i--){
    		totalNum +=tempArr[i];
    		if(totalNum>=i){
    			return i;
    		}
    	}
    	return 0;
    }
}
