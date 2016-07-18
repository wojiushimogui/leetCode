package com.wrh.leetcode;


public class HIndex2 {
	
 	//在N篇paper中至少有h篇论文大于等于h，则才返回h。N篇paper最大值返回N
    public int hIndex(int[] citations) {
    	if(citations==null||citations.length==0){
    		return 0;
    	}
    	int len = citations.length;
    	//特殊情况，citations中的最小值都大于len
    	if(citations[0]>=len){
    		return len;
    	}
    	//由于citations是一个升序数组
    	int begin = 0;
    	int end = len-1;
    	while(begin<=end){
    		int mid =(begin+end)/2;
    		if(citations[mid]==len-mid){//存在len-mid篇paper影响因子大于等于citations[mid]
    			return citations[mid];
    		}
    		else if(citations[mid]<len-mid){//次数过多，看是否还存在更大的
    			begin = mid+1;
    		}
    		else if(citations[mid]>len-mid){//次数过少，
    			end = mid -1;
    		}
    	}
    	//如果在上面的while循坏中都没有找到citations[mid]==len-mid，
    	//则可以说明一点的是在数组中存在len-(end+1)个影响因子大于len-(end+1)
    	return len-(end+1);
    }
}
