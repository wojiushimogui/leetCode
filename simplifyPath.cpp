#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
字符串处理，由于”..”是返回上级目录（如果是根目录则不处理），因此可以考虑用栈来记录路径名，
这里就直接用java来实现，用C由于没有栈结构，可能保存结果稍微要麻烦一点。 
无论用什么语言来实现，需要注意几个细节： 
重复连续出现的’/’，只按1个处理，即跳过重复连续出现的’/’； 
如果路径名是”.”，则不处理； 
如果路径名是”..”（返回上级目录），则需要弹栈，如果栈为空，则不做处理； 
如果路径名为其他字符串，入栈。 
最后，再逐个取出栈中元素（即已保存的路径名），用’/’分隔并连接起来，不过要注意顺序，
栈顶元素是路径的最后面。栈顶元素为路径的最前面的字符。
*/
char* simplifyPath(char* path) {
	int len=strlen(path);
    if(path==NULL||len==0){
    	return NULL;
	}
	
	 
	 
}
