#include<string>
#include<iostream>
#include<cctype>
#include<vector>
using namespace std;

vector<string> split(const string& s)
{
	vector<string> ret;
	typedef string::size_type string_size;
	string_size i=0,j=0;
	while(i != s.size())
	{
		while(i!=s.size()&& isspace(s[i])) i++;
		j = i;

		while(j != s.size()&& (!isspace(s[j]))) j++;
		if(j != i)
		{
			ret.push_back(s.substr(i,j-i));
			i = j;
		}
	}
	return ret;
}
int main()
{
	string s;
	while(getline(cin,s))
	{
		vector<string> result = split(s);

		vector<string>::size_type i;
		for(i=0;i!=result.size();i++)
		{
			cout << result[i] << endl;
		}
	}

	return 0;
}
