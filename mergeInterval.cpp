
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
思路：将数组intervals进行排序，然后再来合并 
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
	//排序 
	qsort(intervals,intervalsSize,sizeof(intervals[0]),cmp); 
	//开辟一段空间来保存结果 
	struct Interval *result=(struct Interval *)malloc(intervalsSize*sizeof(struct Interval));
	if(result==NULL){
		exit(EXIT_FAILURE);
	}
	int index=0;//result数组的下标 
	//开始遍历合并 
	int start=intervals[0].start;
	int end=intervals[0].end; 
	for(int i=1;i<intervalsSize;i++){
		if(intervals[i].start<=end){//有重叠，开始合并 
			end=max(end,intervals[i].end);//取大的值
		}
		else{//说明，没有重叠，保存结果 
			result[index].start=start;
			result[index].end=end;
			index++;
			//更新start和end 
			start=intervals[i].start;
			end=intervals[i].end; 
		} 
		
	}
	//将最后一段的结果进行保存
	result[index].start=start;
	result[index].end=end;
	index++; 
	*returnSize=index;
	return result; 
}
