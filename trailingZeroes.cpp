
/*
思路，统计2和5的个数 
*/
//int min(int a,int b){
//	return a<b?a:b;
//}
//int trailingZeroes(int n) {
//    if(n<0){
//    	return -1;
//	} 
//	if(n==0){
//		return 1;
//	}
//	int twoCount=0;
//	int fiveCount=0;
//	for(int i=1;i<=n;i++){
//		if(i&0x01==0){
//			twoCount++;
//		}
//		if(i%5==0){
//			fiveCount++;
//		}
//	}
//	return min(fiveCount,twoCount);
//}
/*
按照上面的方法来进行统计，报超时 
*/
int trailingZeroes(int n) {
    int zerosCount=0;
    //统计 n整数5/25/125/625等的个数 
	while(n>=5){
		zerosCount+=n/5;
		n=n/5; 
	} 
	return zerosCount; 
}
