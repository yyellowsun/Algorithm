#include<stdio.h>
#include<string.h>
void* mymemmove(void *dest,const void *src,size_t n)
{
	char* d = (char*)dest;
	const char *s = src;
	int i = 0;
	
	//����ʵ�ַ�����һ�����ý�������ʱ�����������ص����ڴ����� 
	//һ���������s>d�������򿽱������s<d�����򿽱���s==d������ 
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
	//��ʼ���ַ���
	//void* memset(void *s,int c,size_t n)��s��ָ�ĵ�ַ�����n���ֽ�ȫ�����Ϊc��ֵ 
	//����s��ָ��λ��   
	//memset(str,0,10);
	//printf("%s",str); 
	//ȡ�ַ����ĳ���
	//size_t strlen(const char* s),���ش�s[0]һֱ��'\0'���û������'\0'��Խ�� 
	char buf[20] = "hello world\n";
	printf("%s",buf);
	mymemmove(buf+2,buf,13);
	printf("%s",buf); 
	return 0;
} 
