

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, bassume caller calls free().
 */
/*
˼·������һ����������ͬ���ȵı�־����binaryArr�������Ԫ�ط�0��1����Ԫ��Ϊ1ʱ����ʾ����nums�е���ͬ��λ������ϡ�
��binaryArr�е�Ԫ��ģ�����������1��������binaryArr�е�Ԫ�ش�ȫ0��ȫ1�󣬾͵õ������е���ϡ� 
*/
int** subsets(int* nums, int numsSize, int** columnSizes, int* returnSize) {
    if(nums==NULL||numsSize<1){
    	return NULL;
	}
	//�ȿ���һ����־����
	int *binaryArr=(int *)malloc(numsSize*sizeof(int));
	if(binaryArr==NULL){
		exit(EXIT_FAILURE);
	} 
	//��ʼ��Ϊ�� 
	memset(binaryArr,0,numsSize*sizeof(int));
	//����һ�οռ����洢���Ľ��
	int total=pow(2,numsSize);//������� 
	int **result=(int **)malloc(total*sizeof(int *));
	if(result==NULL){
		exit(EXIT_FAILURE);
	} 
	//
	int **columnSizes=(int **)malloc(total*sizeof(int*)); 
	while(addOne(binaryArr,numsSize)){//��һ�ɹ�
		//����������Ǽ���Ԫ�ز��������
		
		for(int i=0;i<numsSize;i++){
			if(binaryArr[i]==1){
				
			}
		} 
		
	}
}
