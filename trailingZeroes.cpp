
/*
˼·��ͳ��2��5�ĸ��� 
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
��������ķ���������ͳ�ƣ�����ʱ 
*/
int trailingZeroes(int n) {
    int zerosCount=0;
    //ͳ�� n����5/25/125/625�ȵĸ��� 
	while(n>=5){
		zerosCount+=n/5;
		n=n/5; 
	} 
	return zerosCount; 
}
