#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
using namespace std;
int is_space(char c)
{
	if(c == ' ' || c == '\t' || c == '\n' || c == '\r')
	return 1;
	else 
	return 0;
}

char *shrink_space(char *dest,const char *src,size_t n)
{
	//实现思路类似strncpy，n是dest的字节数 
	size_t i = 0,j=0;
	
	while(i<n && (src[i]!= 0))
	{
		if(is_space(src[i]))
		{
			dest[j++] = ' ';
			while(is_space(src[++i]))
			;
		}//if 具体写法有点问题思考一下
		//开始的写法 if(is_spcae(src[i++])
		//				dest[j++] = ' ';
		//错误在于每次进去判断都i++了 
		//为什么后面一个while不能写成i++?，同样的原因，如果是字符"  c"读到c前面最后一个空白符的时候，
		//再去判断c，进去判断的时候i++了，没有把c存到dest里面。
		//逻辑上，if先判断当前的字符是否为空白符，然后跳到下一个字符去判断与if里面的i相互对应。 
		//Note:pay attention to the i++ or ++i in the CONDITION EXPRESSION!!!!!!!!!!! 
		else
			dest[j++] = src[i++];
	}	
	for(;i<n;i++)
		dest[i] = '\0';
	
	return dest;
}
 
int main(void)
{
	char *str = (char*)malloc(sizeof(char)*5000);
	char dest[1000]= {0};
	
	//实现多组输入字符串 
	//while(scanf()!=EOF)
	char ch;
	char *temp = str;
	while(scanf("%c",&ch)!=EOF)
	{
		*str++ = ch;	
	} 
	shrink_space(dest,temp,sizeof(dest));
	printf("%s\n",dest);
}
