#include<stdio.h>
#include<stdlib.h>
#include<string.h>

bool isValid(string s) {  
        // Start typing your C/C++ solution below  
        // DO NOT write int main() function  
        int len = s.length();  
        if(len==0) return true;  
        if(len%2) return false;  
        for(int i = 1; i < len; i++)  
            if(s[i-1] == '{' && s[i]=='}')  
            {  
                string ss = s.substr(0, i-1) + s.substr(i+1);  
                return isValid(ss);  
            }  
            else if(s[i-1] == '[' && s[i]==']')  
            {  
                string ss = s.substr(0, i-1) + s.substr(i+1);  
                return isValid(ss);  
            }  
            else if(s[i-1] == '(' && s[i]==')')  
            {  
                string ss = s.substr(0, i-1) + s.substr(i+1);  
                return isValid(ss);  
            }  
        return false;  
    }  
    
int main(void){
	
	return 0;
}
