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
#include<math.h>
char oneStr[9][5]= {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
char tenStr[9][5]={"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
char hundredStr[9][5]={"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
char thStr[3][5]={"M", "MM", "MMM"};

int my_integerLen(int x){
	int len=0;
	while(x!=0){
		len++;
		x/=10;
	}
	return len;
}
char *strPoint(int len,int temp){
	switch(len){
		case 1:return oneStr[temp-1];
		case 2:return tenStr[temp-1];
		case 3:return hundredStr[temp-1];
		case 4:return thStr[temp-1];
	}
}
char* intToRoman(int num) {
	char *str;
    int len=my_integerLen(num);
    bool flag=true;
    while(num!=0){
    	int temp=num/(pow(10,len-1));
    	char *str1=strPoint(len,temp);//返回该位代表的字符串 
    	if(flag){//第一次进行复制，之后进行连接
    		str=(char *)malloc((strlen(str1)+1)*sizeof(char));
    		strcpy(str,str1);
    		flag=false;
		}
		else{
			strcat(str,str1);//copy到str中。 
		}
    	
    	//更新x和其长度 
    	num%=((int)(pow(10,len-1)));
    	len=my_integerLen(num);
	}
	return str; 
}

int main(void){
	int num;
	while(scanf("%d",&num)!=EOF){
		char *str=intToRoman(num);
		puts(str);
	}
	return 0;
} 
