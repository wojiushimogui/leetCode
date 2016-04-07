
int countBitOne(int a){
	if(a<0){
		return 0;
	}
	int count=0;
	while(a){
		int temp=a%2;
		count+=temp;
		a=a>>1;
	}
	return count;
}

int* countBits(int num, int* returnSize) {
    if(num<0){
    	return NULL;
	}
	int *res=(int *)malloc((num+1)*sizeof(int));//注意：要开辟num+1个空间 
	for(int i=0;i<=num;i++){
		res[i]=countBitOne(i);
	}
	*returnSize=num+1;
	return res;
}
