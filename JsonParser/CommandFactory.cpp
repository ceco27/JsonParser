#include "CommandFactory.h"
#include "PrintCommand.h"
#include "DeleteCommand.h"
#include "MyString.h"
#include "SetCommand.h"
#include "SaveCommand.h"
#include "SaveAsCommand.h"
#include "CreateCommand.h"
#include "MoveCommand.h"
#include <sstream>

namespace
{
	bool startsWith(const char* first, const char* other)
	{
		int lf = strlen(first);
		int rf = strlen(other);

		if (lf < rf)
			return false;

		for (size_t i = 0; i < rf; i++)
			if (first[i] != other[i])
				return false;

		return true;
	}

	size_t countWords(std::stringstream& stream)
	{
		int currPos = stream.tellg();

		stream.seekg(0);

		MyString currWord;
		size_t count = 0;

		while (stream >> currWord)
			count++;

		stream.clear();
		stream.seekg(currPos);

		return count;
	}
}

Command* CommandFactory::getCommand(SharedPtr<Object> object) const
{
	char buffer[128];
	MyString inputCommand;

	while (true)
	{
		std::cin.getline(buffer, 128);

		std::stringstream inputStream(buffer);

		size_t wordCount = countWords(inputStream);

		inputStream >> inputCommand;

		if (inputCommand == "print")
		{
			if (wordCount == 1)
			{
				return new PrintCommand(object);
			}
			else
			{
				throw std::exception("Invalid input!");
			}
		}
		if (inputCommand == "save")
		{
			if (wordCount == 2)
			{
				MyString path;

				inputStream >> path;

				return new SaveCommand(object, std::move(path));
			}
			else if (wordCount == 1)
			{
				return new SaveCommand(object);
			}
			else
			{
				throw std::exception("Invalid input!");
			}
		}
		if (inputCommand == "saveas")
		{
			if (wordCount == 3)
			{

				MyString fileName;
				MyString path;

				inputStream >> fileName >> path;

				return new SaveAsCommand(object, std::move(fileName), std::move(path));
			}
			else if (wordCount == 2)
			{
				MyString fileName;
				
				inputStream >> fileName;

				return new SaveAsCommand(object, std::move(fileName));
			}
			else
			{
				throw std::exception("Invalid input!");
			}
		}
		if (inputCommand == "delete")
		{
			if (wordCount == 2)
			{
				MyString path;
				inputStream >> path;
				return new DeleteCommand(object, std::move(path));
			}
			else
			{
				throw std::exception("Invalid input!");
			}
		}
		if (inputCommand == "set")
		{
			if (wordCount == 3)
			{
				MyString path;
				MyString value;
				inputStream >> path >> value;
				return new SetCommand(object, std::move(path), std::move(value));
			}
			else
			{
				throw std::exception("Invalid input!");
			}
		}
		if (inputCommand == "create")
		{
			if (wordCount == 3)
			{
				MyString path;
				MyString value;
				inputStream >> path >> value;
				return new CreateCommand(object, std::move(path), std::move(value));
			}
			else
			{
				throw std::exception("Invalid input!");
			}
		}
		if (inputCommand == "move")
		{
			if (wordCount == 3)
			{
				MyString pathFrom;
				MyString pathTo;
				inputStream >> pathFrom >> pathTo;
				return new MoveCommand(object, std::move(pathFrom), std::move(pathTo));
			}
		}
		if (inputCommand == "close")
		{
			throw - 1;
		}
		if (inputCommand == "exit")
		{
			throw - 2;
		}
		
	}

	return nullptr;
}

CommandFactory& CommandFactory::getInstance()
{
	static CommandFactory factory;
	return factory;
}