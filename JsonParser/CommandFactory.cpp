#include "CommandFactory.h"
#include "PrintCommand.h"
#include "DeleteCommand.h"
#include "MyString.h"
#include "SetCommand.h"

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
}

Command* CommandFactory::getCommand(SharedPtr<Object> object) const
{
	MyString inputCommand;

	while (true)
	{
		std::cin >> inputCommand;
		if (inputCommand == "print")
		{
			return new PrintCommand(object);
		}
		if (inputCommand == "save")
		{
			std::exit(0);
		}
		if (inputCommand == "delete")
		{
			MyString path;
			std::cin >> path;
			return new DeleteCommand(object, std::move(path));
		}
		if (inputCommand == "set")
		{
			MyString path;
			MyString value;
			std::cin >> path >> value;
			return new SetCommand(object, std::move(path), std::move(value));
		}
	}

	return nullptr;
}

CommandFactory& CommandFactory::getInstance()
{
	static CommandFactory factory;
	return factory;
}