#include <iostream>
#include <stdlib.h>

using namespace std;


const int X = 100;
const int Y = 100;
const int RADIUS = 5;

char board [X][Y];

void fillBoard()
{
	for (int y = 0; y < Y; y++)
	{
		for (int x = 0; x < X; x++)
		{
			board[x][y] = ' ';
		}
	}
}
void displayBoard()
{
	for (int y = 0; y < Y; y++)
	{

		for (int x = 0; x < X; x++)
		{
			cout << board[x][y];
		}

		cout << endl;
	}

}


bool partOfCircle(int checkX, int checkY)
{
	int x = checkX;
	int y = checkY;

	//cout << x * x << " + " << y * y << " = " << (x * x + y * y) << " = " << ((x * x + y * y) == (RADIUS * RADIUS) || (x * x + y * y) == (RADIUS * RADIUS + 1)) << endl;
	return (x * x + y * y) >= (RADIUS * RADIUS) && (x * x + y * y) <= (RADIUS * RADIUS + RADIUS);
}
void generateCircle(int x, int y)
{

	cout << "x:" << x << ", y:" << y << endl;


	for (int curY = -RADIUS; curY <= RADIUS; curY++)
	{
		for (int curX = -RADIUS; curX <= RADIUS; curX++)
		{
			board[x + curX][y + curY] = (partOfCircle(curX, curY) ? '+' : ' ');
		}
	}

	board[x][y] = 'x';
}

//int main()
//{
//	fillBoard();
//	generateCircle(rand() % 100, rand() % 100);
//	displayBoard();
//
//	
//	return 0;
//}