#pragma once
#include"StringFunctions.h"
#include "ConstantsAndGlobals.h"
#include <iostream>
#include <fstream>
bool isValidLevel(char level[])
{
	for (int i = 0; i < 10; i++)
	{
		if (isEqual(level, LIST_OF_LEVELS[i]))
		{
			return true;
		}		
	}
	return false;
}
void setMatrixes()
{
	drawing = new char* [rows];
	solution = new char* [rows];
	for (int i = 0; i < rows; i++)
	{
		drawing[i] = new char[columns+1];
		solution[i] = new char[columns+1];
	}
}
bool isRowGuessed(int row)
{
	for (int i = colIndex; i < columns; i+=3)
	{
		if (solution[row][i] == 'x')
		{
			continue;
		}
		if (drawing[row][i] != solution[row][i])
		{
			return false;
		}
	}
	return true;
}
bool isColumnGuessed(int col)
{
	for (int i = rowIndex; i < rows; i++)
	{
		if (solution[i][col] == 'x')
		{
			continue;
		}
		if (drawing[i][col] != solution[i][col] )
		{
			return false;
		}
	}
	return true;
}
void setSize()
{
	if (isEqual(difficulty, "Beginner"))
	{
		matrixSize = 3;
	}
	if (isEqual(difficulty, "Easy"))
	{
		matrixSize = 5;
	}
	if (isEqual(difficulty, "Medium"))
	{
		matrixSize = 10;
	}
	if (isEqual(difficulty, "Hard"))
	{
		matrixSize = 15;
	}
	if (isEqual(difficulty, "Expert"))
	{
		matrixSize = 20;
	}
	rows = matrixSize + rowIndex;
	columns = colIndex + 1 + 3 * (matrixSize - 1);
}
void generateNewLevel()
{
	countOfLives = 3;
	char dir[MAX_DIR_SIZE];
	char solutionDir[MAX_DIR_SIZE];
	ConcatanateString(DIR_DRAWING, level, dir);
	appendTxt(dir);
	ConcatanateString(DIR_SOLUTION, level, solutionDir);
	appendTxt(solutionDir);
	std::fstream game;
	game.open(dir);
	char number[3];
	game.getline(number, 3);
	colIndex = stringToInt(number);
	game.getline(number, 3);
	rowIndex = stringToInt(number);
	setSize();
	setMatrixes();
	int i = 0;
	while (game.good())
	{
		game.getline(drawing[i], columns+1);
		i++;
	}
	game.close();
	i = 0;
	std::fstream solFile;
	solFile.open(solutionDir);
	while (solFile.good())
	{
		solFile.getline(solution[i], columns +1);
		i++;
	}
	solFile.close();
}
void Draw()
{
	system("cls");
	
	
	for (int i = 0; i < rows; i++)
	{
		std::cout << drawing[i] << std::endl;
	}
}
void Save()
{
	char dir[MAX_DIR_SIZE];
	ConcatanateString(DIR_LAST_ATTEPMTS, logged,dir);
	appendTxt(dir);
	int size = rowIndex + matrixSize;
	std::ofstream saveAttempt;
	saveAttempt.open(dir);
	saveAttempt << colIndex<<std::endl;
	saveAttempt << rowIndex << std::endl;
	saveAttempt << difficulty << std::endl;
	saveAttempt << level << std::endl;
	saveAttempt << countOfLives << std::endl;
	for (int i = 0; i < size-1; i++)
	{
		saveAttempt << drawing[i] << std::endl;
	}
	saveAttempt << drawing[size - 1];
	saveAttempt.close();
}
void Guess(int row, int col, const char guess[])
{
	row--;
	col--;
	col = colIndex + col * 3;
	row = row + rowIndex;
	if (isEqual(guess, "full"))
	{
		if (solution[row][col] == '*')
		{
			drawing[row][col] = '*';
			if (isRowGuessed(row))
			{
				coppyStr(solution[row], drawing[row]);
			}
			if (isColumnGuessed(col))
			{
				for (int i = rowIndex; i < rows; i++)
				{
					drawing[i][col] = solution[i][col];
				}
			}
		}
		else
		{
			drawing[row][col] = 'x';
			countOfLives--;
		}
	}
	else
	{
		if (solution[row][col] == 'x')
		{
			drawing[row][col] = 'x';
		}
		else
		{
			drawing[row][col] = '*';
			countOfLives--;
		}
	}
	Draw();
}
void LoadAttepmt()
{
	char dir[MAX_DIR_SIZE];
	char solutionDir[MAX_DIR_SIZE];
	char num[3];
	ConcatanateString(DIR_LAST_ATTEPMTS, logged,dir);
	appendTxt(dir);
	std::fstream game;
	game.open(dir);
	game.getline(num, 3);
	colIndex = stringToInt(num);
	game.getline(num, 3);
	rowIndex = stringToInt(num);
	difficulty = new char[12];
	game.getline(difficulty, 12);
	level = new char[13];
	game.getline(level, 13);
	game.getline(num, 3);
	countOfLives = stringToInt(num);
	setSize();
	setMatrixes();
	int i = 0;
	while (game.good())
	{		
		game.getline(drawing[i], columns + 1);
		i++;		
	}
	game.close();
	ConcatanateString(DIR_SOLUTION, level, solutionDir);
	appendTxt(solutionDir);
	i = 0;
	std::fstream solFile;
	solFile.open(solutionDir);
	while (solFile.good())
	{
		solFile.getline(solution[i], columns + 1);
		i++;
	}
	solFile.close();
}
void Exit()
{
	Save();
	for (int i = 0;i < rows; i++)
	{
		delete[] drawing[i];
		delete[] solution[i];
	}
	delete[] drawing;
	delete[] solution;
	delete[] level;
	delete[] difficulty;
}
