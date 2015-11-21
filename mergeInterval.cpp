
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
/*
˼·��������intervals��������Ȼ�������ϲ� 
*/
struct Interval {
      int start;
      int end;
  };
int cmp(const void *a,const void *b){
	return ((struct Interval*)a)->start-(((struct Interval*)b)->start);
}
int max(int a,int b){
    return a>=b?a:b;
}
struct Interval* merge(struct Interval* intervals, int intervalsSize, int* returnSize) {
    if(intervals==NULL||intervalsSize<1){
    	*returnSize=0;
    	return NULL;
	}
	if(intervalsSize==1){
		*returnSize=1;
		return intervals;
	}
	//���� 
	qsort(intervals,intervalsSize,sizeof(intervals[0]),cmp); 
	//����һ�οռ��������� 
	struct Interval *result=(struct Interval *)malloc(intervalsSize*sizeof(struct Interval));
	if(result==NULL){
		exit(EXIT_FAILURE);
	}
	int index=0;//result������±� 
	//��ʼ�����ϲ� 
	int start=intervals[0].start;
	int end=intervals[0].end; 
	for(int i=1;i<intervalsSize;i++){
		if(intervals[i].start<=end){//���ص�����ʼ�ϲ� 
			end=max(end,intervals[i].end);//ȡ���ֵ
		}
		else{//˵����û���ص��������� 
			result[index].start=start;
			result[index].end=end;
			index++;
			//����start��end 
			start=intervals[i].start;
			end=intervals[i].end; 
		} 
		
	}
	//�����һ�εĽ�����б���
	result[index].start=start;
	result[index].end=end;
	index++; 
	*returnSize=index;
	return result; 
}
