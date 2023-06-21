#include "OpenCommand.h"
#include "StrFunctions.h"
#include <fstream>

namespace
{
	void getChars(std::ifstream& is, char* arr)
	{
		size_t count = 0;
		size_t currentPosition = is.tellg();
		while (true)
		{
			char c = is.get();
			if (is.eof())
				break;
			if (c != ' ' && c != '\n' && c != '\t')
				arr[count++] = c;
		}
		is.clear();
		is.seekg(currentPosition);
		arr[count] = '\0';
	}

	int getClosingComma(const MyString& fileStr, size_t from)
	{
		int countCurly = 0;
		int countSquare = 0;
		size_t l = fileStr.length();
		for (size_t i = from; i < l; i++)
		{
			if (fileStr[i] == ',' && countCurly == 0 && countSquare == 0)
				return i;

			if (fileStr[i] == '{')
				countCurly++;
			if (fileStr[i] == '}')
				countCurly--;
			if (fileStr[i] == '[')
				countSquare++;
			if (fileStr[i] == ']')
				countSquare--;

		}

		return -1;
	}
}

OpenCommand::OpenCommand(SharedPtr<Object> mainObj, MyString fileName) : mainObj(mainObj), fileName(std::move(fileName))
{
}

void OpenCommand::execute()
{
	std::ifstream is(fileName.c_str());

	if (!is.is_open())
	{
		throw std::exception("Could not open file!");
	}

	char file[1024];

	getChars(is, file);

	MyString fileStr(file);

	int curr = 1;
	while (true)
	{
		int closingComma = getClosingComma(fileStr, curr);

		if (closingComma == -1)
		{
			mainObj->addToMulti(buildType(fileStr.substr(curr, fileStr.length() - 1 - curr), 1));
			break;
		}
		else
		{
			mainObj->addToMulti(buildType(fileStr.substr(curr, closingComma - curr), 1));
			curr = closingComma + 1;
		}
	}

	is.close();
}

Type* OpenCommand::buildType(const MyString& typeStr, size_t indent)
{
	int indexOfCurly = indexOf(typeStr, '{', 1);
	int indexOfSquare = indexOf(typeStr, '[', 1);

	if (indexOfCurly == -1 && indexOfSquare == -1) // primitive
	{
		return buildPrimitive(typeStr, indent);
	}
	else if (indexOfCurly < indexOfSquare || indexOfSquare == -1) // object
	{
		return buildObject(typeStr, indent);
	}
	else // array
	{
		return buildArray(typeStr, indent);
	}

	return nullptr;
}

Primitive* OpenCommand::buildPrimitive(const MyString& typeStr, size_t indent)
{
	int indexOf1 = indexOf(typeStr, '\"', 1);
	int indexOf2 = indexOf(typeStr, '\"', 2);
	int indexOf3 = indexOf(typeStr, '\"', 3);
	int indexOf4 = indexOf(typeStr, '\"', 4);
	MyString fieldName = typeStr.substr(indexOf1, indexOf2 - indexOf1 + 1);
	MyString value = typeStr.substr(indexOf3, indexOf4 - indexOf3 + 1);

	return new Primitive(fieldName, indent, value);
}

Object* OpenCommand::buildObject(const MyString& typeStr, size_t indent)
{
	return nullptr;
}

Array* OpenCommand::buildArray(const MyString& typeStr, size_t indent)
{
	return nullptr;
}
