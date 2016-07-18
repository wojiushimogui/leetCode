package com.wrh.leetcode;


public class HIndex {
	
	//��Nƪpaper��������hƪ���Ĵ���h����ŷ���h��Nƪpaper���ֵ����N
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
