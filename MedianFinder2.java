package com.wrh.leetcode;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class MedianFinder2 {
	private List<Integer> list = new ArrayList<Integer>();
    // Adds a number into the data structure.
    public void addNum(int num) {
    	int len = list.size();
    	//�ȴ��������������
    	if(len==0){
    		list.add(num);
    		return ;
    	}
    	if(num>=list.get(len-1)){
    		list.add(num);
    		return;
    	}
    	if(num<list.get(0)){
    		list.add(0, num);
    		return ;
    	}
    	//���ö��ֲ����ҵ�numҪ�����λ��
    	int left = 0;
    	int right = len-1;
    	int mid = -1;
    	while(left<=right){
    		mid = left + (right-left)/2;
    		int val = list.get(mid);
    		if(val==num){
    			left = mid;
    			break;
    		}
    		else if(val<num){//�ҵ���һ������num����
    			left = mid+1;
    		}
    		else if(val>num){
    			right = mid-1;
    		}
    	}
    	//leftָ�����Ҫ�����λ��
    	list.add(left, num);
        
    }

    // Returns the median of current data stream
    public double findMedian() {
        
    	//Collections.sort(list);
    	int len = list.size();
    	return (len&0x01)==1?list.get(len/2):(list.get(len/2)+list.get(len/2-1));
    }
    
    public static void main(String[] args){
    	MedianFinder2 mf = new MedianFinder2();
    	Random r = new Random();
    	for(int i=0;i<20;i++){
    		mf.addNum(r.nextInt(100));
    	}
    	for(Integer val:mf.list){
    		System.out.print(val+",");
    	}
    	
    }
}
