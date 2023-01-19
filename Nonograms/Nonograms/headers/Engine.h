#pragma once
#include"Commands.h"
int Run(char* command)
{
	char* mainPart;
	char** listOfArguments;
	int countOfArguments = 0;
	if (command[0] == 0)
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

}