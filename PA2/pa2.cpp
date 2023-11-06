/*

  The following program solves the L-shape blocks problem

   Given
	  A 2^N x 2^N array (In this assignment, we restrict the value N as 1, 2 and 3 )
	   The location of the empty cell (x,y)
		  The legal (x,y) coordinates of the empty cell:

			  For a 2 x 2 block, the legal range is 0-1
			  For a 4 x 4 block, the legal range is 0-3
			  For a 8 x 8 block, the legal range is 0-7
	   You can assume all the input values are correct

	Output:

	  The empty cell (x,y) remains empty
	  All other cells are filled by non-overlapping L-shape block

	Output mode:
	  (0) Console output without normalization
	  (1) Console output with normalization

	   Author: Peter, Brian, Tommy
*/

#include <iostream>
using namespace std;

// Constants in global scope
const int MAX_WIDTH = 8;
const int LOCATEQUADRANT_NOT_IMPLEMENTED = 0;

// TODO:
// function locateQuadrant:
// @param x:  x coordinate of the empty cell
// @param y:  y coordinate of the empty cell
//
// If x < half width, y < half width, then return 1
// If x >= half width, y < half width, then return 2
// If x >= half width, y >= half width, then return 3
// If x < half width, y >= half width, then return 4
//
// @return: int
// The function returns after getting valid values for width, emptyXPos and emptyYPos
int locateQuadrant(int width, int x, int y)
{
	return (x >= width / 2)? ((y >= width / 2)? 3 : 2) : ((y >= width / 2)? 4 : 1);
}

/**
	Given the puzzleMap (2D array from the recursive function),
	Generate the console output
 */
void visualizePuzzleByText(int width, char puzzleMap[][MAX_WIDTH])
{

	cout << "  ";
	for (int x = 0; x < width; x++)
		cout << x << " ";
	cout << endl;

	for (int y = 0; y < width; y++)
	{
		cout << y << ":";
		for (int x = 0; x < width; x++)
			cout << puzzleMap[x][y] << " ";
		cout << endl;
	}
}

/**
 * Initialize the whole puzzleMap using by a space character: ' '
 */
void initializePuzzleMap(int width, char puzzleMap[][MAX_WIDTH])
{
	for (int x = 0; x < width; x++)
		for (int y = 0; y < width; y++)
			puzzleMap[x][y] = ' ';
}

// TODO:
// Normalize the whole puzzleMap. The space character ' ' will not be changed.
//
void normalizePuzzleMap(int width, char puzzleMap[][MAX_WIDTH])
{
	const int deCap = 'a' - 'A';
	const int Cap = 'A' - 'a';
	const char replacechar = 'A';
	const int MAXCHAR = (width * width  - 1) / 3;
	char currentorder[MAXCHAR];
	int countchar = 0;
	for(int i = 0;i < width;i++)
	{
		for(int j = 0;j < width;j++)
		{	
			bool exist = 0;
			if(puzzleMap[j][i] == ' ')continue;
			puzzleMap[j][i] += deCap;
			for(int k = 0;k < MAXCHAR;k++)
			{
				if(puzzleMap[j][i]== currentorder[k])
				{
					exist  = 1;
					break;
				}
			}
			if(exist)continue;
			currentorder[countchar] = puzzleMap[j][i];
			countchar++;
		}
	}
	for(int i = 0;i < width;i++)
		for(int j = 0;j < width;j++)
		{	
			if(puzzleMap[j][i] == ' ')continue;
			for(int k = 0;k < MAXCHAR;k++)
				if(puzzleMap[j][i] == currentorder[k])puzzleMap[j][i] = replacechar + k;
		}
	return;
}

// TODO:
// [The most important function in this program]
// The recursive function to fill up the character array: puzzleMap
// You need to figure out the parameters of the fillPuzzleRecursive function by yourself
//
void fillPuzzleRecursive(int width,char puzzleMap[][MAX_WIDTH], int tx,
						 int ty, int x, int y, char &nextChar)
{
	// tx: top Left X coordinate
	// ty: top Left Y coordinate
	// x:  x coordinate of the empty cell
	// y:  y coordinate of the empty cell
	if (width == 2)
	{
		// The base case...
		for(int i = tx;i <= tx + 1;i++)
			for(int j = ty;j <= ty + 1;j++)
			{	
				if( j == y && i == x) continue;
				puzzleMap[i][j] = nextChar;
			}
		nextChar++;
		return;
	}
	// The general case
	//
	// Key idea:
	//  Because qual must be equal to either 1, 2, 3 or 4
	// As a result:
	//    A L-shape MUST be created at the center of the bigger rectangle
	//    Each Quad MUST have exactly 1 empty space
	int midpointx = tx + width / 2;
	int midpointy = ty + width / 2;
	switch(locateQuadrant(width,x-tx,y-ty))
	{
		case 1:
			fillPuzzleRecursive(2,puzzleMap,midpointx-1,midpointy-1,midpointx-1,midpointy-1,nextChar);
			fillPuzzleRecursive(width/2,puzzleMap,tx,ty,x,y,nextChar);
			fillPuzzleRecursive(width/2,puzzleMap,midpointx,ty,midpointx,midpointy-1,nextChar);
			fillPuzzleRecursive(width/2,puzzleMap,midpointx,midpointy,midpointx,midpointy,nextChar);
			fillPuzzleRecursive(width/2,puzzleMap,tx,midpointy,midpointx-1,midpointy,nextChar);
			return;
		case 2:
			fillPuzzleRecursive(2,puzzleMap,midpointx-1,midpointy-1,midpointx,midpointy-1,nextChar);
			fillPuzzleRecursive(width/2,puzzleMap,tx,ty,midpointx-1,midpointy-1,nextChar);
			fillPuzzleRecursive(width/2,puzzleMap,midpointx,ty,x,y,nextChar);
			fillPuzzleRecursive(width/2,puzzleMap,midpointx,midpointy,midpointx,midpointy,nextChar);
			fillPuzzleRecursive(width/2,puzzleMap,tx,midpointy,midpointx-1,midpointy,nextChar);
			return;
		case 3:
			fillPuzzleRecursive(2,puzzleMap,midpointx-1,midpointy-1,midpointx,midpointy,nextChar);
			fillPuzzleRecursive(width/2,puzzleMap,tx,ty,midpointx-1,midpointy-1,nextChar);
			fillPuzzleRecursive(width/2,puzzleMap,midpointx,ty,midpointx,midpointy-1,nextChar);
			fillPuzzleRecursive(width/2,puzzleMap,midpointx,midpointy,x,y,nextChar);
			fillPuzzleRecursive(width/2,puzzleMap,tx,midpointy,midpointx-1,midpointy,nextChar);
			return;
		case 4:
			fillPuzzleRecursive(2,puzzleMap,midpointx-1,midpointy-1,midpointx-1,midpointy,nextChar);
			fillPuzzleRecursive(width/2,puzzleMap,tx,ty,midpointx-1,midpointy-1,nextChar);
			fillPuzzleRecursive(width/2,puzzleMap,midpointx,ty,midpointx,midpointy-1,nextChar);
			fillPuzzleRecursive(width/2,puzzleMap,midpointx,midpointy,midpointx,midpointy,nextChar);
			fillPuzzleRecursive(width/2,puzzleMap,tx,midpointy,x,y,nextChar);
			return;
	}
	return;
}

// TODO:
// function checkInput:
//
// @param width: the width of the square. Valid values: 2, 4, 8
// You can assume inputs are always integers.
// @param emptyXPos: the x-axis of the empty position.
// Valid range: [0, width-1].
// You can assume inputs are always integers.
// @param emptyYPos: the y-axis of the empty position.
// Valid range: [0, width-1].
// You can assume inputs are always integers.
//
//  Note: The pass-by-reference variables will be used in the main function.
// @return: void
// The function returns after getting valid values for width, emptyXPos and emptyYPos
void checkInput(int &width, int &emptyXPos, int &emptyYPos)
{
	do
	{
		cout << "Enter the width/height of the puzzle (2, 4, 8): "<< endl;
		cin>>width;
	}
	while(width != 2 && width != 4 && width != 8);
	do
	{
		cout << "Enter the x-coordinate of the empty cell (0-" << width - 1 << "): "<< endl;
		cin>>emptyXPos;
	}
	while(emptyXPos < 0 || emptyXPos > width - 1);
	do
	{
		cout << "Enter the y-coordinate of the empty cell (0-" << width - 1 << "): "<< endl;
		cin>>emptyYPos;
	}
	while(emptyYPos < 0 || emptyYPos > width - 1);
	return;
}

// You are NOT ALLOWED to modify the main function
int main()
{

	int width = 0;
	int emptyXPos = 0;
	int emptyYPos = 0;

	checkInput(width, emptyXPos, emptyYPos);

	// initialized with empty spaces..
	char puzzleMap[MAX_WIDTH][MAX_WIDTH];

	// initialize
	initializePuzzleMap(width, puzzleMap);

	int modeOfOperation = 0;
	do
	{
		cout
			<< "0: Exit directly (for testing checkInput function), 1: Output Quadrant of the empty cell,"
			<< endl
			<< "2: Output without normalization (for student's debug only), 3: Output with normalization"
			<< endl;
		cout << "Enter the output mode: ";
		cin >> modeOfOperation;
		cout << endl;
	} while (modeOfOperation < 0 || modeOfOperation > 3);

	if (modeOfOperation == 0)
	{
		return 0;
	}
	if (modeOfOperation == 1)
	{
		int quad = locateQuadrant(width, emptyXPos, emptyYPos);
		cout << "Quadrant for the empty cell: " << quad << endl;
		return 0;
	}
	char nextChar = 'A';

	// invoke the recursive call here...
	// Result: puzzleMap will be filled by characters
	fillPuzzleRecursive(width, puzzleMap, 0, 0, emptyXPos, emptyYPos, nextChar);

	int quad = locateQuadrant(width, emptyXPos, emptyYPos);
	cout << "Quadrant for the empty cell: " << quad << endl;
	if (modeOfOperation == 2)
	{
		visualizePuzzleByText(width, puzzleMap);
	}
	else
	{
		normalizePuzzleMap(width, puzzleMap);
		visualizePuzzleByText(width, puzzleMap);
	}
	return 0;
}
