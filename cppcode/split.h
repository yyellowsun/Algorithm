#include<string>
#include<iostream>
#include<cctype>
#include<vector>

std::vector<std::string> split(const std::string& s)
{
	std::vector<std::string> ret;
	typedef std::string::size_type string_size;
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



