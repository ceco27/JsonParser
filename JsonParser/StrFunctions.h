#pragma once
#include "MyString.h"

static int indexOf(const MyString& str, char c, unsigned count)
{
	size_t l = str.length();
	unsigned currCount = 0;

	for (size_t i = 0; i < l; i++)
	{
		if (str[i] == c)
			currCount++;
		if (currCount == count)
		{
			return i;
		}
	}

	return -1;
}

static size_t countOf(const MyString& str, char c)
{
	size_t l = str.length();
	unsigned count = 0;

	for (size_t i = 0; i < l; i++)
	{
		if (str[i] == c)
			count++;
	}

	return count;
}

static void buildPath(const MyString& pathStr, MyString*& pathArr, size_t& pathSize)
{
	pathSize = countOf(pathStr, '/') + 1;

	pathArr = new MyString[pathSize];

	int indexOfFirst = indexOf(pathStr, '/', 1);

	if (pathSize == 1)
	{
		pathArr[0] = pathStr.substr(1, pathStr.length() - 2);
		return;
	}
	else
	{
		pathArr[0] = pathStr.substr(1, indexOfFirst - 1);
	}
	
	int indexOfLast = indexOfFirst;
	for (size_t i = 1; i < pathSize - 1; i++)
	{
		int indexPrev = indexOf(pathStr, '/', i);
		int indexNext = indexOf(pathStr, '/', i + 1);

		indexOfLast = indexNext;

		pathArr[1] = pathStr.substr(indexPrev + 1, indexNext - indexPrev - 2);
	}

	pathArr[pathSize - 1] = pathStr.substr(indexOfLast + 1, pathStr.length() - indexOfLast - 2);

}