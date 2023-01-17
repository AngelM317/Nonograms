#pragma once
int Length(char str[])
{
	int index = 0;
	while (str[index] != 0)
	{
		index++;
	}
	return index;
}
bool Contains(char str[], char searched[])
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
			for (int j = i; j < searchedLength; j++)
			{
				if (str[j] == searched[j])
				{
					if (j==searchedLength-1)
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
void nullStr(char str[])
{
	int length = sizeof(str);
	for (int i = 0; i < length;i++)
	{
		str[i] = 0;
	}
}

void coppyStr(char str[], char coppy[])
{
	int strLength = strLength;
	if (sizeof(str)>sizeof(coppy))
	{
		for (int i = 0; i <= strLength; i++)
		{
			coppy[i] = str[i];
		}
	}
}
