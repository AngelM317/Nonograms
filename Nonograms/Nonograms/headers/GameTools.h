#pragma once
#include"StringFunctions.h"
#include "ConstantsAndStatics.h"
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
void generateLevel(const char levelName[])
{
	countOfLives = 3;
	char dir[50];
	char solutionDir[50];
	ConcatanateString(DRAWING_DIR, levelName, dir);
	ConcatanateString(SOLUTION_DIR, levelName, solutionDir);
	std::fstream game;
	game.open(dir);
	char number[3];
	game.getline(number, 3);
	colIndex = stringToInt(number);
	game.getline(number, 3);
	rowIndex = stringToInt(number);

	int i = 0;
	while (game.good())
	{
		game.getline(drawing[i], 100);
		i++;
	}
	game.close();
	i = 0;
	std::fstream solFile;
	solFile.open(solutionDir);
	while (solFile.good())
	{
		solFile.getline(solution[i], 100);
		i++;
	}
	solFile.close();
}
void Draw()
{
	system("cls");
	int size = 0;
	if (isEqual(difficulty, "Beginner"))
	{
		size = rowIndex + 3;
	}
	if (isEqual(difficulty, "Easy"))
	{
		size = rowIndex + 5;
	}
	if (isEqual(difficulty, "Medium"))
	{
		size = rowIndex + 10;
	}
	if (isEqual(difficulty, "Hard"))
	{
		size = rowIndex + 15;
	}
	if (isEqual(difficulty, "Expert"))
	{
		size = rowIndex + 20;
	}
	for (int i = 0; i < size; i++)
	{
		std::cout << drawing[i] << std::endl;
	}
}
void Guess(int row, int col, const char guess[])
{
	if (isEqual(guess, "full"))
	{
		if (solution[row + rowIndex][colIndex + col * 3] == '*')
		{
			drawing[row + rowIndex][colIndex + col * 3] = '*';
		}
		else
		{
			drawing[row + rowIndex][colIndex + col * 3] = 'x';
			countOfLives--;
		}
	}
	else
	{
		if (solution[row + rowIndex][colIndex + col * 3] == 'x')
		{
			drawing[row + rowIndex][colIndex + col * 3] = 'x';
		}
		else
		{
			drawing[row + rowIndex][colIndex + col * 3] = '*';
			countOfLives--;
		}
	}
	Draw();
}

