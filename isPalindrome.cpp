/*
Determine whether an integer is a palindrome. Do this without extra space.

����������

û���뵽�Ĳ������� 
1��������x=-121�������ǻ����� 

2��x=1000021,���ǻ����� 
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
    //����������ĳ���
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
		//Ϊ���x=100021�������Ϊ���������������x=1002001���ǻ����������
		//������´���
		int dif=preLen-len-2;
		if(dif!=0){//˵�����λ֮�����ȥ���ˡ� 
			//���������β����û��diff����
			if(x%((int)(pow(10,dif)))){
				return false;
			}
			x/=(int)(pow(10,dif));
		} 
		len=my_length(x);//�ڸ�����len 
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
		x%=((int)(pow(10,len-1)));//�����λȥ�� 
		x/=10;//�����λȥ�� 
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
