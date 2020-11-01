#include<iostream>
#include<vector>
#include<numeric>
#include<iomanip>
using namespace std;

int main()
{
	vector<double> num1 = {1.0,2.0,3.0,4.0,5.0};
	vector<int> num2 = {1,2,3,4,5};
	
	double a =  accumulate(num1.begin(),num1.end(),0.0);
	
	cout << a <<endl;
	cout << accumulate(num2.begin(),num2.end(),0)<<endl;
	
	return 0;
}
