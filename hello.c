#include<stdio.h>
#include<stdlib.h>
char *my_strcpy(char *dest,const char* src)
{
	for(int i =0;src[i]!='\0';i++)
	dest[i] = src[i];

	return dest;	
} 
//others  
//不太明白为啥有个temp？
char *my_strcpy(char *dest, const char*src)
{
    char *temp = dest;
    while(*src)
        *dest++ = *src++;
    return temp;
}
int main(void)
{
	char src[10] = "hello1234";
	char des[5];
	printf(my_strcpy(des,src));
	
	return 0;	 
}
