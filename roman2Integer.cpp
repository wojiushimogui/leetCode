/*Roman to integer*/
/*
�����ַ�	
I V X L C D M
��Ӧ�İ��������ֱ�ʾΪ	
1 5 10 50 100 500 1000
��ͬ��������д������ʾ����������Щ������ӵõ��������磺��=3��
С�������ڴ�����ֵ��ұߡ�����ʾ����������Щ������ӵõ������� �磺��=8����=12��
С�����֡������� ��X �� C���ڴ�����ֵ���ߡ�����ʾ�������ڴ�����С���õ��������磺��=4����=9��
����ʹ��ʱ����д�������ظ����ó������Ρ��������ϵ��ĵ��ӡ�IIII�����⣩��
��һ���������滭һ�����ߡ���ʾ��������� 1000 ����
*/

/*
˼·��
���������֡�

1~9: {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

10~90: {"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};

100~900: {"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};

1000~3000: {"M", "MM", "MMM"}. 
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int roman2Num(char ch){
	int res=0;
	switch(ch){
		case 'I':
			res=1;
			break;
		case 'V':
			res=5;
			break;
		case 'X':
			res=10;
			break;
		case 'L':
			res=50;
			break;
		case 'C':
			res=100;
			break;
		case 'D':
			res=500;
			break;
		case 'M':
			res=1000;
			break;
		default:
			;			
	}
	return res;
}
int romanToInt(char* s) {
    if(s==NULL){
    	return 0;
	}
	int len=strlen(s);
	//��s��ͷ��ʼ����
	int result=roman2Num(s[0]); 
	for(int i=1;i<len;i++){
		if(roman2Num(s[i-1])>=roman2Num(s[i])){//��������С����ǰ��Ӧ�������
			result+=roman2Num(s[i]);			 			
		}
		else{//С�����ڴ�����ǰ��Ӧ�ô����ּ�ȥ�����֣�����֮ǰ���Ǽ���һ��С���֣����Ҫ��С���ֵ����������磺s="IV"
			result+=(roman2Num(s[i])-2*roman2Num(s[i-1]));
		}
	}
	return result; 
}

int main(void){
	char s[100];
	while(gets(s)){
		int result=romanToInt(s);
		printf("%d\n",result);
	}
	
}
