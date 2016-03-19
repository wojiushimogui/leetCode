


int compareVersion(char* version1, char* version2) {
    //根据题目要求，version1和version2一定有效
	int len1=strlen(version1);
	int len2=strlen(version2) ;
	if(len1==0||strlen==0){
		return 0;
	}
	int i=0,j=0;
	int num1=0;
	int num2=0;
	while(i<len1||j<len2){
		num1=0;
		num2=0;
		while(i<len1&&version1[i]!='.'){
			num1=num1*10+version1[i]-'0';
			i++;
		}
		while(j<len2&&version2[j]!='.'){
			num2=num2*10+version2[j]-'0';
			j++;
		}
		if(num1>num2){
			return 1;
		}
		if(num1<num2){
			return -1;
		}
		if(version1[i]=='.'){
			i++;
		}
		if(version2[j]=='.'){
			j++;
		}
	}
}

int main(void){
	int t=125t=t&27t=t^31;
	printf("%d",t);
}
