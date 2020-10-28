#include<iostream>
#include<algorithm>
#include<iterator>
#include<vector>
#include<string>
using namespace std;
//对于重载函数，写自己的函数来指明使用哪个版本的重载函数
bool space(char c)
{
	return isspace(c);
}

bool not_space(char c)
{
	return !isspace(c);
}

vector<string> split(const string& str)
{
	typedef string::const_iterator iter;
	iter i = str.begin(),j;
	vector<string> ret;

	while(i != str.end())
	{
//find_if(i,j,func) 用第三个参数作为谓词函数，查找从iterator[i,j)开始的序列
//如果谓词为真，则返回当前iterator的位置，如果一直没找到则返回j
		i = find_if(i,str.end(),not_space);

		j = find_if(i,str.end(),space);
		
		if(i!=str.end()) ret.push_back(string(i,j));
		i = j;
	}
	return ret;
}
int main()
{
	vector<string> test = split("hello world a   b     c  d e fg");
	vector<string>::iterator i;
//i是迭代器
	for(i = test.begin();i!=test.end();i++)
		cout << *i << endl;

	return 0;
}
