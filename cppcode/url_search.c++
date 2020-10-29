#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<iterator>
#include<cctype>
using namespace std;
typedef string::const_iterator iter;

iter url_beg(iter b,iter e)
{
	static const string sep = "://";
	iter i = b;
	//search函数接受四个参数，前两个为从中查找的序列，后两个为查找的对象
	//如果没找到就返回第二个参数，如果找到了，则返回找到的位置
	while((i = search(i,e,sep.begin(),sep.end()))  != e)
	{
	//确保分隔符不是唯一的符号，只能保证分隔符前后都有字符，但不保证有效
		if(b!=i && (i+sep.size()!=e))
		{
			//用beg标记url的开头
			iter beg = i;
			while(beg!=b && isalpha(beg[-1])) beg--;
			
			//确保分隔符后面有东西,并且前面至少有一个字符
			if(beg != i && isalnum(i[sep.size()])) return beg;
		}	

		i += sep.size();
	}
	//如果没找到则跳过这个字符串
	return e;
}

bool not_url(char c)
{
	static const string url_ch = "~;/?:@=&$-_.+!*'(),'";
	//find 从[i，j)查找是否有一个和c值相同的
	//isalnum判断是否为一个字符或者数字
	return !(isalnum(c) || find(url_ch.begin(),url_ch.end(),c)!= url_ch.end());

}
//从 [b,e)找到一个不是url字符的，如果没找到，则返回e
iter url_end(iter b,iter e)
{
	return find_if(b,e,not_url);
}


//从输入的字符串中查找url的基本思路：
//1、先找到"://"
//2、从分隔符前面找协议名
//3、从分隔符后面找资源名
vector<string> find_url(const string& s)
{
	 vector<string> ret;
	 iter b = s.begin();
	 iter e = s.end();
	 while(b!=e)
	 {
		iter after;
		b = url_beg(b,e);
		if(b!=e) 
		 {
			 after = url_end(b,e);
			 ret.push_back(string(b,after));

			b = after;
		 }
	 }
	
	 return ret;
}

int main()
{	

	//有点小问题
	string str = "abcd  ://abcd/n https://www.baidu.com\n ftp://mycomputer\n balabalalba\nfile://helloworld\n";
	vector<string> vec = find_url(str);

	vector<string>::iterator i;
	for(i = vec.begin(); i!=vec.end();i++)
		cout << *i << endl;

	return 0;
}
