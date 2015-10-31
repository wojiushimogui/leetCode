/*
Given a string, find the length of the longest substring without repeating characters. 
For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. 
For "bbbbb" the longest substring is "b", with the length of 1.
*/

/*
思路： 字符串中的字符由于并没有说明是大写或小写或者还包含其它的，因此如果采用哈希来做，则需要开辟256个int空间。 
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
	//将flag初始化为-1  
	memset(flag,-1,N*sizeof(int ));
	//求出字符串s的长度
	int len=strlen(s); 
	int maxLen=0;//用来保存最大长度 
	int start=0;//用来表示每次检测时的开始起点 
	
	for(int i=0;i<len;i++){
		if(flag[s[i]]!=-1){//此种情况说明：遇到了重复字符
			 //只有重复的字符在现有的检查范围内，才算是遇到了重复字符。
			 int preIndex=flag[s[i]];
			 if(preIndex>=start){//在当前检查范围内遇到了重复字符。 
			 	int tempMax=i-start;
			 	if(tempMax>maxLen){
			 		maxLen=tempMax;
				 }
				 //更新检查范围的起点
				 start=preIndex+1; 
				 
			 } 
			//更新重复字符的下标
			 flag[s[i]]=i;
			
		}
		else{
			flag[s[i]]=i;//将下标保存 
		}
		
	}
	// 在最后一个字符中没有重复的子字符串的长度和maxLen中去最大值就是我们所求的值；例如：aabc，最后一个start到字符串结束由于上面并没有与maxLen比较大小。因此需要比较 
	return maxLen>(len-start)?maxLen:(len-start); 
}

int main(void){
	char s[100];
	while(gets(s)){
		int len=lengthOfLongestSubstring(s) ;
		printf("%d\n",len);
	}
}


