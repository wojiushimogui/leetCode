

uint32_t reverseBits(uint32_t n) {
	int len=32;
	int res=(n&0x01);
    for(int i=1;i<len;i++){
    	n>>=1;
    	res<<=1; 
		res|=(n&0x01);  	
	}
	return res;
}
#include<stdio.h>
int main(void){
	
	printf("%d ",1<<31);
}
