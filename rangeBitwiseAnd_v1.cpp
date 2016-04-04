
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
		//�ȼ����m��n�ǲ�����һ��������,�������Ʊ�ʾ�ϵ����λ�ǲ�����ͬһ����λ�� 
		if(!isSameLever(m,n)){
			return 0;
		} 
		//��m/n ��ͬһ������ʱ 	
    	//���m~n֮��Ŀ�ȣ���Ⱦ;�����������Ӧ����m�ĵͶ���λӦ�ñ�Ϊ0�� 
    	int dif=n-m;
    	if(dif!=0&&isTwoPow(n)){//�ȼ���Ƿ�nΪ2��ָ���η� 
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
