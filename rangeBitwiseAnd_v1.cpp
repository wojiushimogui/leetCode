
#define MAXVALUE  2147483647

bool isTwoPow(int n){
	if(n<0){
		return false;
	}
	while(n!=1){
		int remainder=n%2;
		if(remainder!=0){
			return false;
		}
		n=n>>1;
	}
	return true ;
}
bool isSameLever(int m,int n){
	if(m<0||n<0){
		return false;
	}
	while(m>0&&n>0){
		m=m>>1;
		n=n>>1;
	}
	int dif=n-m;
	if(dif==0){
		return true;
	}
	else {
		return false;
	}
}
int rangeBitwiseAnd(int m, int n) {
    if(0<=m&&m<=MAXVALUE&&m<=n){ 
		//先检查下m和n是不是在一个量级上,即二进制表示上的最高位是不是在同一比特位上 
		if(!isSameLever(m,n)){
			return 0;
		} 
		//当m/n 在同一量级上时 	
    	//求出m~n之间的跨度，跨度就决定了输出结果应该是m的低多少位应该变为0； 
    	int dif=n-m;
    	if(dif!=0&&isTwoPow(n)){//先检查是否n为2的指数次方 
    		return 0;
		}
    	int count=0;
    	while(dif){
    		count++;
    		dif=dif>>1; 		
		}
		m=m>>count;
		m=m<<count;		
		return m;		
	}
	return 0;
}
