#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
#include <cfloat>

using namespace std;

int main()
{
	int i,n;
	cin >> n;
	double maxArea=0,minArea=DBL_MAX;
	long int minIdx=0,maxIdx=0,idx=1;
	while(n--)
	{
		double a,b,c;
		double x[3],y[3];

		for(i=0;i<3;i++)
		{
			cin >> x[i];
			cin >> y[i];
		}
		a=sqrt((x[0]-x[1])*(x[0]-x[1])+(y[0]-y[1])*(y[0]-y[1]));
		b=sqrt((x[1]-x[2])*(x[1]-x[2])+(y[1]-y[2])*(y[1]-y[2]));
		c=sqrt((x[0]-x[2])*(x[0]-x[2])+(y[0]-y[2])*(y[0]-y[2]));

		double s=(a+b+c)/2;

		double area = sqrt(s*(s-a)*(s-b)*(s-c));
		if(area>=maxArea)
		{
			maxArea=area;
			maxIdx=idx;
		}
		if(area<=minArea)
		{
			minArea=area;
			minIdx=idx;
		}
		idx++;
	}

	cout << minIdx << " " << maxIdx << endl;
}