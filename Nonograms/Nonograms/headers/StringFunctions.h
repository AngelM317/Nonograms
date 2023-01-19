#pragma once
#include<iostream>
int Length(const char str[])
{
	int index = 0;
	while (str[index] != 0)
	{
		index++;
	}
	return index;
}
bool Contains(const char str[],const char searched[])
{
	int strLength = Length(str);
	int searchedLength = Length(searched);
	if (searchedLength > strLength)
	{
		return false;
	}
	else
	{
		for (int i = 0; i <= strLength - searchedLength; i++)
		{
			for (int j = i; j < searchedLength+i; j++)
			{
				if (str[j] == searched[j-i])
				{
					if (j-i==searchedLength-1)
					{
						return true;
					}					
				}
				else
				{
					break;
				}
			}
		}
		return false;
	}
}

void coppyStr(const char str[], char coppy[])
{
	int strLength = Length(str);	
		for (int i = 0; i < strLength; i++)
		{
			coppy[i] = str[i];
		}
		coppy[strLength] = 0;
		
}

bool isEqual(const char str1[], const char str2[])
{
	int str1Length = Length(str1);
	if (str1Length != Length(str2))
	{
		return false;
	}
	for (int i = 0; i < str1Length;i++)
	{
		if (str1[i] != str2[i])
		{
			return false;
		}
	}
	return true;
}
int stringToInt(const char str[])
{
	
	int sum = 0;
	int length = Length(str);
	for (int i = 0; i < length; i++)
	{
		sum *= 10;
		sum += str[i] - '0';
	}
	return sum;
}
/**
 * Concatanates username and password in 1 strings with '/' for split.
 *
 * @param {string} First string in the concatanation.
 * @param {string} Second string in the concatanation.
 * @param {string} The result.
 */
bool ConcatanateString(const char str1[], const char str2[], char result[])
{		
	int index = 0;
	while (str1[index] != 0)
	{
		result[index] = str1[index++];
	}
	result[index++] = '/';
	int index2 = 0;
	while (str2[index2] != 0)
	{
		result[index + index2] = str2[index2++];
	}
	result[index + index2] = 0;
	return true;	
}
//appends .txt to string
void appendTxt(char str[])
{
	int length = Length(str);
	str[length] = '.';
	str[length + 1] = 't';
	str[length + 2] = 'x';
	str[length + 3] = 't';
	str[length + 4] = 0;
}
bool isInt(char str[])
{
	int index = 1;
	if (Length(str) == 0)
	{
		return false;
	}
	if (str[0] == '0' && str[1] != 0)
	{
		return false;
	}
	while (str[index] != 0)
	{
		if (str[index] < '0' || str[index++]>'9')
		{
			return false;
		}
	}
	return true;
}