/*
Ë¼Â·£º
 the bitwise and of the range is keeping the common bits of m and n from left to right 
 until the first bit that they are different, padding zeros for the rest. 
*/
#define MAXVALUE  2147483647

int rangeBitwiseAnd(int m, int n) {
    if(0<=m&&m<=MAXVALUE&&m<=n){
    	int i=0;
    	for(;m!=n;i++){
    		m=m>>1;
    		n=n>>1;
		}
		return n<<i;
	}
	return 0;
}
