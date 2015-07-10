#include <iostream>

using namespace std;

int main()
{
	long long int n;
	long long int a;

	cin >> n;
	while(n--){
		cin >> a;
		long long int a2=a;
		while(a2%10==0)
			a2/=10;
		if(a2%5==0){
			int count=0;
			while(a2%5==0){
				a2/=5;
				count++;
			}
			if(count%2!=0)
				count++;
			count/=2;
			while(count--)
				a*=4;
			if(count)
			cout << a << endl;
		}
		else
			cout << a << endl;
	}
}