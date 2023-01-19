#pragma once
#include"Commands.h"
//Handles commands
int Run(char* command)
{
	char* mainPart;
	char** listOfArguments;
	int countOfArguments = 0;
	if (command[0] != '/')
	{
		std::cout << MESSAGE_INVALID_COMAND << std::endl;
	}
	else
	{
		countOfArguments = SplitComand(command, mainPart, listOfArguments);
		if (countOfArguments == -1)
		{
			std::cout << MESSAGE_INVALID_COMAND << std::endl;
		}
		else
		{
			ExecuteComand(mainPart, listOfArguments, countOfArguments);
		}
		delete[] mainPart;
		if (countOfArguments > 0)
		{
			for (int i = 0; i < countOfArguments; i++)
			{
				delete[] listOfArguments[i];
			}
			delete[] listOfArguments;
		}
		return countOfArguments;
	}	
}
void Start()
{
	std::cout << MESSAGE_WELCOME << std::endl;
	std::cout << std::endl;
	std::cout << RULES << std::endl;
	std::cout << MESSAGE_HELP << std::endl;
	while (1)
	{
		char* comand = new char[MAX_INPUT_SIZE];
		std::cin.getline(comand, 100);
		if (Run(comand) == -1)
		{
			break;
		}
	}
	std::cout << MESSAGE_GOODBYE;
}