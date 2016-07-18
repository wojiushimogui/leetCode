package com.wrh.leetcode;


public class HIndex2 {
	
 	//��Nƪpaper��������hƪ���Ĵ��ڵ���h����ŷ���h��Nƪpaper���ֵ����N
    public int hIndex(int[] citations) {
    	if(citations==null||citations.length==0){
    		return 0;
    	}
    	int len = citations.length;
    	//���������citations�е���Сֵ������len
    	if(citations[0]>=len){
    		return len;
    	}
    	//����citations��һ����������
    	int begin = 0;
    	int end = len-1;
    	while(begin<=end){
    		int mid =(begin+end)/2;
    		if(citations[mid]==len-mid){//����len-midƪpaperӰ�����Ӵ��ڵ���citations[mid]
    			return citations[mid];
    		}
    		else if(citations[mid]<len-mid){//�������࣬���Ƿ񻹴��ڸ����
    			begin = mid+1;
    		}
    		else if(citations[mid]>len-mid){//�������٣�
    			end = mid -1;
    		}
    	}
    	//����������whileѭ���ж�û���ҵ�citations[mid]==len-mid��
    	//�����˵��һ������������д���len-(end+1)��Ӱ�����Ӵ���len-(end+1)
    	return len-(end+1);
    }
}
