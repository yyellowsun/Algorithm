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
	//ʵ��˼·����strncpy��n��dest���ֽ��� 
	size_t i = 0,j=0;
	
	while(i<n && (src[i]!= 0))
	{
		if(is_space(src[i]))
		{
			dest[j++] = ' ';
			while(is_space(src[++i]))
			;
		}//if ����д���е�����˼��һ��
		//��ʼ��д�� if(is_spcae(src[i++])
		//				dest[j++] = ' ';
		//��������ÿ�ν�ȥ�ж϶�i++�� 
		//Ϊʲô����һ��while����д��i++?��ͬ����ԭ��������ַ�"  c"����cǰ�����һ���հ׷���ʱ��
		//��ȥ�ж�c����ȥ�жϵ�ʱ��i++�ˣ�û�а�c�浽dest���档
		//�߼��ϣ�if���жϵ�ǰ���ַ��Ƿ�Ϊ�հ׷���Ȼ��������һ���ַ�ȥ�ж���if�����i�໥��Ӧ�� 
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
	
	//ʵ�ֶ��������ַ��� 
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
