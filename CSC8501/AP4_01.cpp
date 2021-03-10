#include <iostream>
#include <stdlib.h>

using namespace std;
int dPoints = 0;
int squareRoot[2];
bool imaginary = false;
int mySqrt(const int sqr, int lowerBound, int upperBound)
{
	int mid;
	while (upperBound > lowerBound + 1)
	{
		mid =	lowerBound + ((upperBound - lowerBound) / 2);
		if (mid * mid == sqr)
		{
			squareRoot[0] = mid;
			return 0;
		}
		else if (mid * mid > sqr)
		{
			upperBound = mid;
		}
		else
		{
			lowerBound = mid;
		}
	}
	squareRoot[0] = lowerBound;

	//sort out decimal;
	int dif = (sqr - lowerBound * lowerBound) * 10;
	cout << "base = " << squareRoot[0] << endl;
	cout << "difference = " << dif << endl;

	int decimal = 0;
	
	for (int degree = 0; degree < dPoints; degree++)
	{

		upperBound = dif;
		lowerBound = 0;
		while (upperBound > lowerBound + 1)
		{
			cout << "lowerbound = " << lowerBound << endl;
			cout << "upperbound = " << upperBound << endl;
			mid = lowerBound + ((upperBound - lowerBound) / 2);
			cout << "mid = " << mid << endl;

			if (mid * mid == dif)
			{
				cout << "found it" << endl;
				squareRoot[1] = decimal + mid;
				return 0;
			}
			else if (mid * mid > dif)
			{
				cout << "lower" << endl;
				upperBound = mid;
			}
			else
			{
				cout << "upper" << endl;
				lowerBound = mid;
			}
		}
		decimal = (decimal + lowerBound) * 10;
		
		dif = (dif - lowerBound * lowerBound) * 10;
		cout << squareRoot[0] << "." << decimal << endl;
		cout << "dif = " << dif << endl;

	}

	squareRoot[1] = decimal;

}

void rootIt(int sqr)
{
	//imaginary = sqr >= 0 ? false : true;
	
	if (sqr == 0)
	{
		squareRoot[0] = 0;
		squareRoot[1] = 0;
	}
	//else if (sqr >= 0 && sqr < 1)
	//{
	//	mySqrt(sqr, sqr, 1);
	//}
	else
	{
		mySqrt(sqr, 0, sqr);
	}

}

//int main()
//{
//	int x;
//	cout << "number to be square rooted:";
//	cin >> x;
//	cout << "to ho many dpoints:";
//	cin >> dPoints;
//
//	rootIt(x);
//
//	cout << squareRoot[0] << "." << squareRoot[1];
//}
