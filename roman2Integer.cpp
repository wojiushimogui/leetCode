/*Roman to integer*/
/*
基本字符	
I V X L C D M
相应的阿拉伯数字表示为	
1 5 10 50 100 500 1000
相同的数字连写、所表示的数等于这些数字相加得到的数、如：Ⅲ=3；
小的数字在大的数字的右边、所表示的数等于这些数字相加得到的数、 如：Ⅷ=8、Ⅻ=12；
小的数字、（限于 Ⅰ、X 和 C）在大的数字的左边、所表示的数等于大数减小数得到的数、如：Ⅳ=4、Ⅸ=9；
正常使用时、连写的数字重复不得超过三次。（表盘上的四点钟“IIII”例外）；
在一个数的上面画一条横线、表示这个数扩大 1000 倍。
*/

/*
思路：
【罗马数字】

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
	//将s从头开始遍历
	int result=roman2Num(s[0]); 
	for(int i=1;i<len;i++){
		if(roman2Num(s[i-1])>=roman2Num(s[i])){//大数字在小数字前，应两者相加
			result+=roman2Num(s[i]);			 			
		}
		else{//小数字在大数字前，应该大数字减去见数字，但是之前我们加了一次小数字，因此要减小数字的两倍，例如：s="IV"
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
