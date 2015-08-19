#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	long int n;
	cin >> n;
	
	while(n--)
	{
		long long int num1,num2,dummy1,dummy2;
		cin >> num1;
		cin >> num2;
	
		vector<long long int> vector1;
		vector<long long int> vector2;
	
		dummy1=num1;
		dummy2=num2;
	
		while(dummy1)
		{
			vector1.push_back(dummy1);
			dummy1/=2;
		}
	
		while(dummy2)
		{
			vector2.push_back(dummy2);
			dummy2/=2;
		}
	
		vector <long long int> :: iterator it1;
		vector <long long int> :: iterator it2;
	
		it1 = find(vector1.begin(),vector1.end(),num2);
		if(it1!=vector1.end())
		{
			cout << (it1-vector1.begin()) << endl;
			continue;
		}
	
		it2 = find(vector2.begin(),vector2.end(),num1);
		if(it2!=vector2.end())
		{
			cout << (it2-vector2.begin()) << endl;
			continue;
		}
	
	
		it1=vector1.end();
		it2=vector2.end();
		it1--;it2--;
	
		while((*it1)==(*it2))
		{
			it1--;
			it2--;
		}
	
		cout << (it1-vector1.begin())+(it2-vector2.begin())+2 << endl;
	}

}