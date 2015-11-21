


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
//思路：通过遍历，在intervals中
int min(int a,int b){
	return a<=b?a:b;
}
int max(int a,int b){
	return a>=b?a:b;
}
struct Interval* insert(struct Interval* intervals, int intervalsSize, struct Interval newInterval, int* returnSize) {
//    if(intervals==NULL||intervalsSize<1){//特殊情况 
//    	*returnSize=1;
//    	return &newInterval; 
//	} 	
	struct Interval* result=(struct Interval*)malloc((intervalsSize+1)*sizeof(struct Interval));
	if(result==NULL){
		exit(EXIT_FAILURE);
	}
	int index=0;
	int index1=-1;
	for(int i=0;i<intervalsSize;i++){
		if(newInterval.end<intervals[i].start){
			index1=i;//数组中从index1开始就与newInterval就没有重叠 
			break;
		}
		else if(newInterval.start>intervals[i].end){//也与newInterval没有重叠,将其保存即可 
		 	result[index]=intervals[i];
		 	index++;
		} 
		else{//newInterval.start<intervals[i].end&&newInterval.end>intervals[i].start;有重叠 
			//更新即可
			newInterval.start=min(newInterval.start,intervals[i].start);
			newInterval.end=max(newInterval.end,intervals[i].end); 
		} 
	}
	result[index]=newInterval;
	index++;
	if(index1!=-1){//要判断下是否还有元素要放入到结果中去 
		for(int j=index1;j<intervalsSize;j++){
			result[index]=intervals[j];
			index++;
		} 
	}
	
	*returnSize=index;
	return result;
 
}
