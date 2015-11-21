


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
//˼·��ͨ����������intervals��
int min(int a,int b){
	return a<=b?a:b;
}
int max(int a,int b){
	return a>=b?a:b;
}
struct Interval* insert(struct Interval* intervals, int intervalsSize, struct Interval newInterval, int* returnSize) {
//    if(intervals==NULL||intervalsSize<1){//������� 
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
			index1=i;//�����д�index1��ʼ����newInterval��û���ص� 
			break;
		}
		else if(newInterval.start>intervals[i].end){//Ҳ��newIntervalû���ص�,���䱣�漴�� 
		 	result[index]=intervals[i];
		 	index++;
		} 
		else{//newInterval.start<intervals[i].end&&newInterval.end>intervals[i].start;���ص� 
			//���¼���
			newInterval.start=min(newInterval.start,intervals[i].start);
			newInterval.end=max(newInterval.end,intervals[i].end); 
		} 
	}
	result[index]=newInterval;
	index++;
	if(index1!=-1){//Ҫ�ж����Ƿ���Ԫ��Ҫ���뵽�����ȥ 
		for(int j=index1;j<intervalsSize;j++){
			result[index]=intervals[j];
			index++;
		} 
	}
	
	*returnSize=index;
	return result;
 
}
