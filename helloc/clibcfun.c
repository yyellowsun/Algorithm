#include<stdio.h>
#include<string.h>
void* mymemmove(void *dest,const void *src,size_t n)
{
	char* d = (char*)dest;
	const char *s = src;
	int i = 0;
	
	//两种实现方法，一种是用借助于临时缓冲区处理重叠的内存区域。 
	//一种是如果有s>d，就正向拷贝，如果s<d则逆向拷贝，s==d不拷贝 
	if(s>d)
	{
		for(i=0;i<n;i++)
		d[i] = s[i];
	}
	else 
	{
		i = 0;
		s = s+n-1;
		d = d+n-1;
		while(n--)
		{
			d[i--] = s[i--];
		}
	}
	return dest;
}
int main(void)
{
	char str[10];
	//printf("%s\n",str);
	//初始化字符串
	//void* memset(void *s,int c,size_t n)将s所指的地址后面的n个字节全部填充为c的值 
	//返回s所指的位置   
	//memset(str,0,10);
	//printf("%s",str); 
	//取字符串的长度
	//size_t strlen(const char* s),返回从s[0]一直到'\0'如果没有遇到'\0'会越界 
	char buf[20] = "hello world\n";
	printf("%s",buf);
	mymemmove(buf+2,buf,13);
	printf("%s",buf); 
	return 0;
} 
