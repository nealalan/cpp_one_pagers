// MouseIsland.cpp
// page 767 number 5
// author: Ken Serrine
//
// any key will end the program after the current simulation runs
//
#include <iostream.h>
#include <fstream.h>
#include <windows.h>
#include <winbase.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include "MI_console.h"

const int MAX_ISLAND_SIZE = 20;
const int MAX_MOVES = 100;
const char BRIDGE = 'B';
const char WATER = '#';
const char LAND = ' ';
const char MOUSE = '*';

struct events {
	int times_escaped;
	int times_drowned;
	int times_starved;
};


// define some constants for the mouse's status
const int SEARCHING = 0;
const int ESCAPED = 1;
const int STARVED = 2;
const int DROWNED = 3;

void LoadMap(char [][MAX_ISLAND_SIZE], int&, int&, int&);
void ShowMap(char [][MAX_ISLAND_SIZE], int, events, int, int, int, int);
int MoveMouse(char [][MAX_ISLAND_SIZE], int&, int&, int&);

void main()
{
	char island[MAX_ISLAND_SIZE][MAX_ISLAND_SIZE];
	int mouseRow, mouseCol, mouseStartRow, mouseStartCol;
	int mouseStatus;
	int moveNumber = 0;
	int simulationNumber = 0;
	int island_size;
	events mouse_stats = { 0,0,0};

	srand( (unsigned)time( NULL ) );	// seed to random number generator

	MI_ClearScreen();
	LoadMap(island, island_size, mouseStartRow, mouseStartCol);
	
	do
	{
		mouseStatus = SEARCHING;
		moveNumber = 0;
		mouseRow = mouseStartRow;
		mouseCol = mouseStartCol;

		// initialize the island map and get the initial mouse position
//		MI_ClearScreen();
		ShowMap(island, simulationNumber, mouse_stats, moveNumber, island_size, mouseRow, mouseCol);
		Sleep(0);
		
		while ( mouseStatus == SEARCHING )
		{
			mouseStatus = MoveMouse(island, moveNumber, mouseRow, mouseCol);
			ShowMap(island, simulationNumber, mouse_stats, moveNumber, island_size, mouseRow, mouseCol);
			Sleep(200);	// pause for a bit
		}

		switch (mouseStatus)
		{
		case STARVED:	mouse_stats.times_starved++; break;
		case DROWNED:	mouse_stats.times_drowned++; break;
		case ESCAPED:	mouse_stats.times_escaped++; break;
		}
		
		simulationNumber++;

	} while (!_kbhit());

	_getch();	// absorb key hit
	MI_SetCursorPos(23,0);
}
// end of main function

//
// initialize the map array by loading a map file from disk
//
void LoadMap(char island[][MAX_ISLAND_SIZE], int& island_size, int& mouseRow, int& mouseCol)
{
	ifstream ISLAND;
	int row, col;
	int marker;

	ISLAND.open("island.txt", ios::nocreate);

	if (!ISLAND)
	{
		cout << "Error: Could not open island map file" << endl;
		exit(1);
	}

	ISLAND >> island_size;
	
	for (row = 0; row < island_size; row++)
	{
		for (col = 0; col < island_size; col++)
		{
			ISLAND >> marker;

			if (marker == -1)	//water
			{
				island[row][col] = WATER;
			}
			else if (marker == 0)	// dry land or bridge
			{
				if ((row == (island_size-1)) || 
					(row == 0) || (col == 0) || 
					(col == (island_size - 1)))	// bridge
				{
					island[row][col] = BRIDGE;
				}
				else island[row][col] = LAND;
			}
			else if (marker == 1)	// mouse position
			{
				island[row][col] = LAND;
				mouseRow = row;
				mouseCol = col;
			}
		}
	}

	ISLAND.close();
}

//
// Pick a random direction for the mouse to move and move it.
// Update the mouse coordinates.
// Update the status message.
// Return the mouse's status.
//
int MoveMouse(char island[][MAX_ISLAND_SIZE], int& moveNumber, int& mouseRow, int& mouseCol)
{
	int mouseStatus;
	int direction;

	// pick a random direction
	direction = rand() % 4;	// let 0 be up, 1 be right, 2 be down, and 3 be left

	// put cursor in status row
	MI_SetCursorPos(23,0);
	cout << "                                                            " << flush;
	MI_SetCursorPos(23,0);

	// update the move number
	moveNumber++;
	
	// update the mouse's coordinates
	switch (direction)
	{
	case 0:	// up
		mouseRow--;
		break;
	case 1:	// right
		mouseCol++;
		break;
	case 2:	// down
		mouseRow++;
		break;
	case 3:
		mouseCol--;
		break;
	}

	if (island[mouseRow][mouseCol] == BRIDGE)
	{
		mouseStatus = ESCAPED;
		cout << "Mouse escaped!";
	}
	else if (island[mouseRow][mouseCol] == WATER)
	{
		mouseStatus = DROWNED;

		if (moveNumber >= MAX_MOVES)
			cout << "Mouse starved and drowned.";
		else
			cout << "Mouse sleeps with the fishes.";
	}
	else if (moveNumber >= MAX_MOVES)
	{
		mouseStatus = STARVED;
		cout << "Mouse starved.";
	}
	else
	{
		mouseStatus = SEARCHING;
		cout << "Mouse is searching...";
	}

	cout << flush;
	return mouseStatus;
}

//
// display the map array to the console
//
void ShowMap(char island[][MAX_ISLAND_SIZE], int simulationNumber,
			 events mouse_stats,
			 int moveNumber, int island_size, int mouseRow, int mouseCol)
{
	int row,col;

	MI_SetCursorPos(0,0);	// upper left corner

////////////
// INSERT your code here for displaying the island
//    Use island_size for the max row and column size and
//      use the multidimensional island array for source data
//

	row = col = 0;
	while (row < island_size) {
		
		while (col < island_size) {
			cout << island[row][col];
			col++;
		}
		col = 0;
		cout << endl;
		row++;
	}


	
	// put the mouse
	MI_SetCursorPos(mouseRow, mouseCol);
	cout << MOUSE << flush;

	MI_SetCursorPos(3,27);
	cout << "Move #    " << flush;
	MI_SetCursorPos(3,34);
	cout << moveNumber << flush;

	MI_SetCursorPos(4,27);
	cout << "Times escaped: " << mouse_stats.times_escaped << flush;

	MI_SetCursorPos(5,27);
	cout << "Times starved: " << mouse_stats.times_starved << flush;

	MI_SetCursorPos(6,27);
	cout << "Times drowned: " << mouse_stats.times_drowned << flush;

	MI_SetCursorPos(7,27);
	cout << "Simulation number: " << simulationNumber << flush;

	MI_SetCursorPos(8,27);
}

