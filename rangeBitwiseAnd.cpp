
#define MAXVALUE  2147483647

int rangeBitwiseAnd(int m, int n) {
    if(0<=m&&m<=MAXVALUE&&m<=n){
    	int res=m;
    	for(int i=m+1;i<=n;i++){
    		res&=i;
		}
		return res;
	}
	return 0;
}
