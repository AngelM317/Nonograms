#pragma once
#include<fstream>
#include<iostream>
#include"StringFunctions.h"
#include"ConstantsAndGlobals.h";

int getAccountsCount()
{
	std::fstream accountsCount;
	accountsCount.open("files/AccountsCount.txt");
	char count[10];
	accountsCount.getline(count, 10);
	accountsCount.close();
	return stringToInt(count);

}
void getAllAccounts(char** result)
{
	int index = 0;
	std::fstream accounts;
	accounts.open("files/Accounts.txt");
	while (accounts.good())
	{
		char username[13];
		char password[16];
		accounts.getline(username, MAX_USERNAME_SIZE+1);
		if (Length(username) == 0)
		{
			break;
		}
		accounts.getline(password, MAX_PASSWORD_SIZE+1);
		ConcatanateString(username, password, result[index]);
		index++;
	}
	accounts.close();
}
/**
 * Splits username and password in 2 strings.
 *
 * @param {string} Concatanated Username and Password ("username/password").
 * @param {string} String in which the username is saved.
 * @param {string} String in which the password is saved.
 */
void SplitAccountInfo(char accountStr[], char username[], char password[])
{
	int index = 0;
	while (accountStr[index] != '/')
	{
		username[index] = accountStr[index];
		index++;
	}
	username[index++] = 0;
	int index2 = 0;
	while (accountStr[index] != 0)
	{
		password[index2++] = accountStr[index++];
	}
	password[index2] = 0;

}
bool validateUsername(const char username[])
{
	int usernameLength = Length(username);
	if (usernameLength < MIN_USERNAME_SIZE)
	{
		std::cout << "Username is too short. Minimum symbols: 5\n";
		return false;
	}
	if (usernameLength > MAX_USERNAME_SIZE)
	{
		std::cout << "Username is too long. Maximum symbols: 12\n";
		return false;
	}
	if (Contains(username, (char*)"/") || Contains(username, (char*)"#") || Contains(username, (char*)"$"))
	{
		std::cout << "Usernaame can't contain the following symbols: '/' '#' '$'\n";
		return false;
	}
	int accountsCount = getAccountsCount();
	char** accounts = new char* [accountsCount];
	for (int i = 0; i < accountsCount; i++)
	{
		accounts[i] = new char[50];
	}
	getAllAccounts(accounts);
	for (int i = 0; i < accountsCount; i++)
	{
		char existingUsername[MAX_USERNAME_SIZE+1];
		char existingPassword[MAX_PASSWORD_SIZE+1];
		SplitAccountInfo(accounts[i], existingUsername, existingPassword);
		if (isEqual(existingUsername, username))
		{
			for (int j = 0; j < accountsCount; j++)
			{
				delete[] accounts[j];
			}
			delete[] accounts;
			std::cout << "This username is taken. Registration failed\n";
			return false;
		}
	}
	for (int i = 0; i < accountsCount; i++)
	{
		delete[] accounts[i];
	}
	delete[] accounts;
	
	return true;
}

bool validatePaswword(const char password[])
{
	int passwordLength = Length(password);
	if (passwordLength < MIN_PASSWORD_SIZE)
	{
		std::cout << "Password is too short. Minimum symbols: 7\n";
		return false;
	}
	if (passwordLength >MAX_PASSWORD_SIZE)
	{
		std::cout << "Password is too long. Maximum symbols: 16\n";
		return false;
	}
	if (Contains(password, (char*)"/") || Contains(password, (char*)"#") || Contains(password, (char*)"$"))
	{
		std::cout << "Password can't contain the following symbols: '/' '#' '$'\n";
		return false;
	}
	return true;
}
void Register(const char username[], char const password[])
{
	if (validateUsername(username) && validatePaswword(password))
	{
		std::ofstream accounts;
			accounts.open("files/Accounts.txt", std::ios_base::app);
			accounts << username<< "\n";
			accounts << password << "\n";
			accounts.close();
			std::cout << "User: " << username << " registrated successfully" << std::endl;
			logged = new char[Length(username) + 1];
			coppyStr(username, logged);
			isLogged = true;
			std::cout << "Welcome: " << username<<std::endl;
			int accountCount = getAccountsCount();
		std::ofstream CountOfAccounts;
		CountOfAccounts.open("files/AccountsCount.txt");
		CountOfAccounts << accountCount + 1;
		CountOfAccounts.close();

	}
	
}
bool Login(const char logUsername[], const char logPassword[])
{
	int accountsCount = getAccountsCount();
	char** accounts = new char* [accountsCount];
	for (int i = 0; i < accountsCount; i++)
	{
		accounts[i] = new char[29];
	}
	getAllAccounts(accounts);
	
	for (int i = 0; i < accountsCount; i++)
	{
		char username[13];
		char password[16];
		SplitAccountInfo(accounts[i], username, password);
		if (isEqual(logUsername, username) && isEqual(logPassword, password))
		{
			logged = new char[Length(username) + 1];
			coppyStr(logUsername, logged);
			isLogged = true;
			std::cout << "Login successfully. Welcome: " << username << std::endl;
			for (int i = 0; i < accountsCount; i++)
			{
				delete[] accounts[i];
			}
			delete[] accounts;
			return true;
		}
	}
	std::cout << "Login failed. Incorrect username or password" << std::endl;;
	for (int i = 0; i < accountsCount; i++)
	{
		delete[] accounts[i];
	}
	delete[] accounts;
	return false;
}
