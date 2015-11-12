


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
/*
思路：先对candidates进行排序，然后用递归思想来求解即可.
这个题用C不太好实现。这个题用java来实现比较简单 
*/
int** combinationSum(int* candidates, int candidatesSize, int target, int** columnSizes, int* returnSize) {
    if(candidates==NULL||candidatesSize<1){
    	return NULl;
	}
    
}
