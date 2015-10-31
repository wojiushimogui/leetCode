/*
Given a string, find the length of the longest substring without repeating characters. 
For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. 
For "bbbbb" the longest substring is "b", with the length of 1.
*/

/*
˼·�� �ַ����е��ַ����ڲ�û��˵���Ǵ�д��Сд���߻����������ģ����������ù�ϣ����������Ҫ����256��int�ռ䡣 
*/

#include<stdio.h>
#include<stdlib.h> 
#include<string.h>
#define N  256

int lengthOfLongestSubstring(char* s) {
    if(s==NULL){
		return 0;
	}
	int *flag=(int *)malloc(N*sizeof(int));
	if(flag==NULL)
		exit(EXIT_FAILURE);
	//��flag��ʼ��Ϊ-1  
	memset(flag,-1,N*sizeof(int ));
	//����ַ���s�ĳ���
	int len=strlen(s); 
	int maxLen=0;//����������󳤶� 
	int start=0;//������ʾÿ�μ��ʱ�Ŀ�ʼ��� 
	
	for(int i=0;i<len;i++){
		if(flag[s[i]]!=-1){//�������˵�����������ظ��ַ�
			 //ֻ���ظ����ַ������еļ�鷶Χ�ڣ��������������ظ��ַ���
			 int preIndex=flag[s[i]];
			 if(preIndex>=start){//�ڵ�ǰ��鷶Χ���������ظ��ַ��� 
			 	int tempMax=i-start;
			 	if(tempMax>maxLen){
			 		maxLen=tempMax;
				 }
				 //���¼�鷶Χ�����
				 start=preIndex+1; 
				 
			 } 
			//�����ظ��ַ����±�
			 flag[s[i]]=i;
			
		}
		else{
			flag[s[i]]=i;//���±걣�� 
		}
		
	}
	// �����һ���ַ���û���ظ������ַ����ĳ��Ⱥ�maxLen��ȥ���ֵ�������������ֵ�����磺aabc�����һ��start���ַ��������������沢û����maxLen�Ƚϴ�С�������Ҫ�Ƚ� 
	return maxLen>(len-start)?maxLen:(len-start); 
}

int main(void){
	char s[100];
	while(gets(s)){
		int len=lengthOfLongestSubstring(s) ;
		printf("%d\n",len);
	}
}


