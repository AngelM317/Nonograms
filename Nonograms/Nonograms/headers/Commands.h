#pragma once
#include "Users.h"
#include "GameTools.h";
#include <iostream>
void Help()
{
	if (isLogged)
	{
		if (inGame)
		{
			for (int i = 0; i < 4; i++)
			{
				std::cout << LIST_OF_INGAME_COMANDS[i] << std::endl;
			}
		}
		else
		{
			for (int i = 0; i < 5; i++)
			{
				std::cout << LIST_OF_OFFGAME_COMANDS[i] << std::endl;
			}
		}
	}
	else
	{
		for (int i = 0; i < 3; i++)
		{
			std::cout << LIST_OF_STARTING_COMANDS[i] << std::endl;
		}
	}
}
int SplitComand(char *comand,char* &mainPart, char** &listOfArguments)
{
	if (comand[0] != '/')
	{
		return -1;
	}
	int coutOfArguments = 0;
	int i = 1;
	while (comand[i] != 0)
	{
		if (comand[i] == ' ')
		{
			if (comand[i + 1] == ' ')
			{
				return -1;
				break;
			}
			coutOfArguments++;
		}
		i++;
	}
	if (coutOfArguments > 3)
	{
		return -1;
	}
	else
	{
		i = 0;
		int size = 0;
		while (comand[i] != 0&&comand[i]!=' ')
		{
			size++;
			i++;
		}
		mainPart = new char[size+1];
		for (int j = 0; j < size; j++)
		{
			mainPart[j] = comand[j];
		}
		mainPart[size] = 0;
		if (comand[i] != 0)
		{
			listOfArguments = new char* [coutOfArguments];
			i++;
			int sizeOfArgument = 0;
			int ArgSizeIterator = i;
			for (int s = 0; s < coutOfArguments; s++)
			{
				while (comand[ArgSizeIterator] != 0 && comand[ArgSizeIterator] != ' ')
				{
					ArgSizeIterator++;
					sizeOfArgument++;
				}
				listOfArguments[s] = new char[sizeOfArgument + 1];
				for (int j = 0; j < sizeOfArgument; j++)
				{
					listOfArguments[s][j] = comand[j + i];
				}
				listOfArguments[s][sizeOfArgument] = 0;
				ArgSizeIterator++;
				i = ArgSizeIterator;
				sizeOfArgument = 0;
			}
			return coutOfArguments;
			
			
		}
		else
		{
			return  coutOfArguments;
		}
		
		

	}
}
void ExecuteComand(char comand[],char* listOfArguments[],int &countOfArguments)
{
	if (isEqual(comand, "/close") && countOfArguments == 0)
	{
		countOfArguments = -1;
		Close();
	}
	else if (isEqual(comand, "/help")&& countOfArguments==0)
	{
		Help();
	}
	else if(isEqual(comand, "/login") && countOfArguments == 2)
	{
	    if (!isLogged)
	   	{
			Login(listOfArguments[0], listOfArguments[1]);
		}
		else
		{
			std::cout << MESSAGE_NO_PERMISSION << std::endl;
		}
		
	}
	else if(isEqual(comand, "/register") && countOfArguments == 2)
	{
		if (!isLogged)
		{
			Register(listOfArguments[0], listOfArguments[1]);
		}
		else
		{
			std::cout << MESSAGE_NO_PERMISSION << std::endl;
		}
		
	}
	else if (isEqual(comand, "/last")&&countOfArguments==0)
	{
		if (isLogged && !inGame)
		{
			LoadAttepmt();
		}
		else
		{
			std::cout << MESSAGE_NO_PERMISSION << std::endl;
		}
	}
	else if (isEqual(comand, "/levels")&&countOfArguments==0)
	{
		if (isLogged && !inGame)
		{
			std::cout << ListOfAvailableLevels << std::endl;
		}
		else
		{
			std::cout << MESSAGE_NO_PERMISSION << std::endl;
		}
	}
	else if (isEqual(comand, "/guess") && countOfArguments == 3 && (isEqual(listOfArguments[2], "full") || isEqual(listOfArguments[2], "empty"))&&isInt(listOfArguments[0])&&isInt(listOfArguments[1]))
	{
		if (inGame)
		{
			int row = stringToInt(listOfArguments[0]);
			int col = stringToInt(listOfArguments[1]);
			if (row <= matrixSize && row > 0 && col <= matrixSize && col > 0)
			{
				Guess(row, col, listOfArguments[2]);
			}
			else
			{
				std::cout << MESSAGE_INDEX_OUT_OF_RANGE << std::endl;
			}
		}
		else
		{
			std::cout << MESSAGE_NO_PERMISSION << std::endl;
		}
	}
	else if (isEqual(comand, "/exit") && countOfArguments == 0)
	{
		if (isLogged)
		{
			if (inGame)
			{
				system("cls");
				Exit();
				std::cout << MESSAGE_SUCCESSFULL_SAVE << std::endl;
				std::cout << MESSAGE_LOGOUT << std::endl;
			}		
		}
		else
		{
			std::cout << MESSAGE_NO_PERMISSION << std::endl;
		}
	}
	else if (isEqual(comand, "/save") && countOfArguments == 0)
	{
		if (inGame)
		{
			Save();
			Draw();
			std::cout << MESSAGE_SUCCESSFULL_SAVE << std::endl;

		}
		else
		{
			std::cout << MESSAGE_NO_PERMISSION << std::endl;
		}
	}
	else if (isEqual(comand, "/play") && countOfArguments == 1)
	{
		if (!inGame && isLogged)
		{
			for (int i = 0; i < 10; i++)
			{
				if (isEqual(listOfArguments[0], LIST_OF_LEVELS[i]))
				{
					if (Contains(ListOfAvailableLevels, listOfArguments[0]))
					{
						level = new char[Length(listOfArguments[0]) + 1];
						coppyStr(listOfArguments[0], level);
						for (int i = 0; i < 5; i++)
						{
							if (Contains(level, LIST_OF_DIFFICULTIES[i]))
							{
								difficulty = new char[Length(LIST_OF_DIFFICULTIES[i]) + 1];
								coppyStr(LIST_OF_DIFFICULTIES[i], difficulty);
							}
						}
						LoadNewLevel();
						break;
					}
					else
					{
						std::cout << MESSAGE_LEVEL_PERMISSION_DENIED << std::endl;
					}
				}
				if (i == 9)
				{
					std::cout << MESSAGE_INVALID_LEVEL << std::endl;
				}
			}
		}
		else
		{
			std::cout << MESSAGE_NO_PERMISSION << std::endl;
		}
	}
	else
	{
		std::cout << MESSAGE_INVALID_COMAND << std::endl;

	}
}