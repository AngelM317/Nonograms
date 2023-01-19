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
int SplitComand(char comand[],char* &mainPart, char** &listOfArguments)
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
void ExecuteComand(char comand[],char* listOfArguments[],int countOfArguments)
{
	if (isEqual(comand, "/help")&& countOfArguments==0)
	{
		Help();
	}
	else
	{
		std::cout << MESSAGE_INVALID_COMAND<<std::endl;
	}
	if (isEqual(comand, "/login") && countOfArguments == 2)
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
	else if(isEqual(comand, "/login") && countOfArguments == 2)
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
			Guess(stringToInt(listOfArguments[0]), stringToInt(listOfArguments[1]), listOfArguments[2]);
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
			Exit();
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
		}
		else
		{
			std::cout << MESSAGE_NO_PERMISSION << std::endl;
		}
	}
	else if (isEqual(comand, "/load") && countOfArguments == 1)
	{
		if (!inGame && isLogged)
		{
			for (int i = 0; i < 10; i++)
			{
				if (isEqual(listOfArguments[0], LIST_OF_LEVELS[i]))
				{
					coppyStr(listOfArguments[0], level);
					LoadNewLevel();
					break;
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