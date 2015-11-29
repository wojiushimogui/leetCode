#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Note: It is intended for the problem statement to be ambiguous.
 You should gather all requirements up front before implementing one.
*/
/*
˼·�����һ���ַ����Ƿ�������
��һ�������ַ���ǰ�󲿷ֵĿո�ȥ��
�ڶ�����վ���ַ�e�ĽǶȿ�ʼ��飬 eֻ�ܳ���һ�Σ�e���ܳ����ڵ�һλ�����һλ ��e��ǰ����������ֺ͵㣬
e�ĺ�����������ֺͼӼ��ţ����ǼӼ��Ų��������һλ ����¼�ַ�e��e����Ӽ��ŵ�λ�� 
����������������ַ������Ƿ�����˲��� + - ����  ����+ - ֻ�ܳ������ַ���һλ����e����ļӼ���֮�⣩����ֻ�ܳ���һ�Σ��� 
*/

int dotCount=1;
char* trim(char *s){
	char *result;
	int len=strlen(s);
	int i=0;//Ѱ�ҵ�һ�����ǿո���ַ���λ�� 
	for(;i<len;i++){
		if(s[i]!=' '){
			break;
		}
	}
	int j=len-1;//Ѱ�����һ�����ǿո���ַ���λ��
	for(;j>=0;j--){
		if(s[j]!=' '){
			break;
		}
	}
	result=(char *)malloc((j-i+2)*sizeof(char));
	for(int k=i;k<=j;k++){
		result[k-i]=s[k];
	} 
	result[j-i+1]='\0';
	//puts(result);
	return result;
}
//����ַ��Ƿ�������  e �� �� �� 
bool isVaild(char ch){
	if((ch>='0'&&ch<='9')){
		return true;
	}
	if(ch=='.'&&dotCount!=0){//���Ƶ�'.'ֻ�ܳ���һ�� 
		dotCount--;
		return true;
	}
	return false; 
}
bool isdot(char *s,int begin,int end) {
	if(s==NULL||end<begin){
		return false;
	}
	for(int i=begin;i<end;i++){
		if(s[i]=='.'){
			return false;
		}
	}
	return true;
}
bool isNumber(char* s) {
	if(s==NULL||strlen(s)<1){//��Ч�Լ�� 
		return false;
	}
    dotCount=1;
	int eCount=1;
    char *s1=trim(s); //ȥ���ַ���ǰ�󲿷ֵĿո� 
    int len=strlen(s1);
    if(len<1){//�����ȥ���ո����ַ��������Ƿ����1 
        return false;
    }
    int eIndex=-1;//����e���ֵ�λ��  
    int markIndex=-1;//����e����Ӻŵ�λ�� 
    for(int i=0;i<len;i++){//�����eǰ��ͺ����Ƿ���һ������
    	
		if(s1[i]=='e'){
			if(eCount==0){//eֻ�������һ�� 
				return false;
			}
			eCount--;
			eIndex=i;//��¼e���ֵ�λ�� 
			if(i==0||i==len-1){//e����������ڵ�һλ�����һλ��λ�� 
				return false;
			}
			else{
				//e��ǰ��һ��Ҫ�����ֻ�����. 
				if(!(s1[i-1]>='0'&&s1[i-1]<='9'||(dotCount==1&&s1[i-1]=='.'))){
					return false;
				}
				//e�ĺ��治�����е㣬���磺3e. ��3e3.8 
				if(!isdot(s1,i+1,len)){//e�ĺ��治������ֵ�
					return false;
				}
				//��e�ĺ��� ���Գ��ּӼ��� ,��¼����ֵ�λ�� ,������ּӼ��ţ���Ӽ��ű��벻�����һλ 
				if(s1[i+1]=='+'||s1[i+1]=='-'){
					markIndex=i+1;
					if(markIndex==len-1){//������ּӼ��ţ���Ӽ��ű��벻�����һλ
						return false;
					} 
					continue;
				}
				if(!(s1[i+1]>='0'&&s1[i+1]<='9')){ 
					return  false; 
				}
			}
		} 
    	
	}
	
    for(int i=0;i<len;i++){
    	if(i==markIndex||i==eIndex){
    		continue;
		} 
    	if(i==0){
    		//��0��λ�ÿ��Գ��ּӼ��źͷ��ŵ� 
    		if(s1[0]=='+'||s1[0]=='-'||s1[0]=='.'){
    			if(s1[0]=='.'){
    		        dotCount--;//���Ƶ������Ϊ1 
    		    }
    		    if(len==1){//���������ֻ��һ�� + - .
    		        return false;
    		    }
    		    else  {//������ȴ���1����Ӻš����š��͵����һ��Ҫ��һ������,�Ӻźͼ��ź��������һ���� 
    		    	if((dotCount==1&&s1[1]=='.'&&len==2)){//����������������ġ�-."���� 
    		    		return false;
					}
					else if(!(s1[1]>='0'&&s1[1]<='9'||dotCount==1&&s1[1]=='.')){
						return false;
					}
    		    	
				}
    		    
    			continue;
			}
		}
    	if(!isVaild(s1[i])){
    		return false;
		}
	}
	return true;
}


int main(void){
	char str[50];
	while(gets(str)){
		
		bool result=isNumber(str);
		if(result){
			printf("true\n");
		}
		else{
			printf("false\n");
		}
	}
	return 0;
}
