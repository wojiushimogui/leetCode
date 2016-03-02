
//思路：任何一个整数模9同余于该数字在各数位上的数字之和。 
int addDigits(int num){
    if(num<0){
    	return 0;
	}
	return num%9;
}
