// MI_console.cpp
// MouseIsland console functions
// author: Ken Serrine
// purpose: CS125 student labs

#include <windows.h>
#include <winbase.h>
#include <wincon.h>

// clears the console
void MI_ClearScreen()
{
	DWORD NumberOfCharsWritten;
	COORD _ = { 0, 0 };
	static HANDLE hOutput;
  
	hOutput = GetStdHandle (STD_OUTPUT_HANDLE);

  FillConsoleOutputCharacter (
	hOutput,    //  handle to screen buffer 
    ' ',        //  character to write 
    0xffff,         //  number of character cells to write to 
    _,          //  x- and y-coordinates of first cell 
    &NumberOfCharsWritten  //  throw this number away
    );

  SetConsoleCursorPosition (hOutput, _);
}


// sets our cursor position
void MI_SetCursorPos(int row, int col)
{
	COORD _ = { col, row };
	static HANDLE hOutput;
	
	hOutput = GetStdHandle (STD_OUTPUT_HANDLE);

	SetConsoleCursorPosition (hOutput, _);
}
