/*��Ŀ����
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.
�����������������������ϡ� 
Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

*/
/*
����java��ʵ�ֵġ� 
*/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
 //��ֻ����2~9 
 //1������������ 
 //2���ݹ鷨 
char** letterCombinations(char* digits, int* returnSize) {
    if(digits==NULL){
    	return digits;
	}
	int len=strlen(digits);
	if(len==1){
		
	}
}



int main(void){
	char str[100];
	while(gets(str)){
		int returnSize=0;
		char **result=letterCombinations(str, &returnSize);
	}
	return 0;
}
