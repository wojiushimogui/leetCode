package com.wrh.leetcode;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class MedianFinder {
	private List<Integer> list = new ArrayList<Integer>();
    // Adds a number into the data structure.
    public void addNum(int num) {
        list.add(num);
    }

    // Returns the median of current data stream
    public double findMedian() {
        
    	Collections.sort(list);
    	int len = list.size();
    	return (len&0x01)==1?list.get(len/2):(list.get(len/2)+list.get(len/2-1));
    }
}
