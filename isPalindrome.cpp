/*
Determine whether an integer is a palindrome. Do this without extra space.

测试用例：

没有想到的测试用例 
1）负数：x=-121，，不是回文数 

2）x=1000021,不是回文数 
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int my_length(int x){
	int len=0;
	while(x!=0){
		len++;
		x/=10;
	}
	return len;
}
bool isPalindrome(int x) {
    //先求这个数的长度
    if(x<0){
    	return false;
	}
	int len=my_length(x); 
	if(len==1)
	 	return true;
	bool flag=true;
	int preLen=len+2; 
	while(x!=0){
		len=my_length(x);
		//为解决x=100021这种情况为回文数的情况，和x=1002001不是回文数的情况
		//添加如下代码
		int dif=preLen-len-2;
		if(dif!=0){//说明最高位之后的零去掉了。 
			//这样检查下尾端有没有diff个零
			if(x%((int)(pow(10,dif)))){
				return false;
			}
			x/=(int)(pow(10,dif));
		} 
		len=my_length(x);//在更新下len 
		preLen=len;
		if(len==1){
			break;
		} 
		int temp1=x%10;		
		int temp2=x/((int)(pow(10,len-1)));				
		if(temp1!=temp2){
			flag=false;
			break;
		}
		x%=((int)(pow(10,len-1)));//将最高位去掉 
		x/=10;//将最低位去掉 
	}	
	return flag;
}

int main(void){
	int num;
	while(scanf("%d",&num)!=EOF){
		bool flag=isPalindrome(num);
		if(flag){
			printf("yes\n");
		} 
		else{
			printf("NO\n");
		}
	}
	return 0;
}
