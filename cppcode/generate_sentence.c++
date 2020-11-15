#include<vector>
#include<iostream>
#include<map>
#include<stdexcept>
#include<cstdlib>
#include"split.h"
using namespace std;

typedef vector<string> Rule;
typedef vector<Rule> Rule_collection;
typedef map<string,Rule_collection> Grammer;

int nrand(int n)
{
	if(n<=0||n>RAND_MAX)
		throw domain_error("Argument to nrang is out of range");
	const int bucket_size = RAND_MAX/n;
	int r;
	do r = rand()/bucket_size;
	while(r>=n);
	return r;
}
Grammer read_grammer(istream &in)
{
	Grammer ret;
	vector<string> entry;
	string line;
	
	while(getline(in,line))
	{
		entry = split(line);
	
		if(!entry.empty())
		ret[entry[0]].push_back(Rule(entry.begin()+1,entry.end()));
	}
	return ret;
}

bool bracketed(const string&s)
{
	return s.size()>1 && s[0]=='<' && s[s.size()-1] == '>';
}

void gen_aux(const Grammer& g,const string& word,vector<string>& ret)
{
	if(!bracketed(word)) {
		ret.push_back(word);
	}
	else{
		Grammer::const_iterator i = g.find(word);

		if(i == g.end())
			throw logic_error("empty rule");  
		const Rule_collection& c = i->second;
		//随机从规则集中选取一条规则 
		const Rule& r = c[nrand(c.size())];
		//遍历这条规则中的string
		for(Rule::const_iterator j = r.begin();j!=r.end();j++)
			gen_aux(g,*j,ret); 
	}
 
}

vector<string> gen_sentence(const Grammer& g)
{
	vector<string> ret;
	gen_aux(g,"<sentence>",ret);
	return ret;
}
 
int main()
{
	vector<string> sentence = gen_sentence(read_grammer(cin));

	vector<string>::iterator i = sentence.begin();
	if(!sentence.empty())
	{
		cout << *i;
		i++;
	}
	
	for(;i!=sentence.end();i++)
		cout<<" " << *i;
	
	return 0;
} 
/*
input example:

<noun> cat
<noun> dog
<noun> table
<verb> play
<verb> hit
<verb> jumps
<location> where it wants
<location> under the sky
<sentence> the <noun> <verb> <noun> <verb> <location>
*/
