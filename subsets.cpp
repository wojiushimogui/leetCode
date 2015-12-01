

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, bassume caller calls free().
 */
/*
思路：开辟一个与数组相同长度的标志数组binaryArr，里面的元素非0即1，当元素为1时，表示数组nums中的相同的位参与组合。
当binaryArr中的元素模拟二进制数加1操作，当binaryArr中的元素从全0到全1后，就得到了所有的组合。 
*/
int** subsets(int* nums, int numsSize, int** columnSizes, int* returnSize) {
    if(nums==NULL||numsSize<1){
    	return NULL;
	}
	//先开辟一个标志数组
	int *binaryArr=(int *)malloc(numsSize*sizeof(int));
	if(binaryArr==NULL){
		exit(EXIT_FAILURE);
	} 
	//初始化为零 
	memset(binaryArr,0,numsSize*sizeof(int));
	//开辟一段空间来存储最后的结果
	int total=pow(2,numsSize);//结果总数 
	int **result=(int **)malloc(total*sizeof(int *));
	if(result==NULL){
		exit(EXIT_FAILURE);
	} 
	//
	int **columnSizes=(int **)malloc(total*sizeof(int*)); 
	while(addOne(binaryArr,numsSize)){//加一成功
		//检查数组中那几个元素参与了组合
		
		for(int i=0;i<numsSize;i++){
			if(binaryArr[i]==1){
				
			}
		} 
		
	}
}
