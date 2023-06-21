#include <iostream>
#include <sstream>
#include "CommandExecutor.h"
#include "CommandFactory.h"
#include "SaveCommand.h"
#include "OpenCommand.h"

int main()
{
	CommandExecutor executor;
	Object* object = new Object(MyString(), 0);
	while (true)
	{
		char inputLine[128];
		std::cin.getline(inputLine, 1024);

		std::stringstream input(inputLine);

		char inputCommand[32];
		char fileName[32];
		input.getline(inputCommand, 32, ' ');
		input.getline(fileName, 32);
		if (strcmp(inputCommand, "open") == 0)
		{
			CommandExecutor executor(new SaveCommand(object, fileName));
			executor.setCommand(new OpenCommand(object, fileName));
			executor.execute();
			while (true)
			{
				executor.setCommand(CommandFactory::getInstance().getCommand(object));
				executor.execute();
			}
			return 0;
		}
		else
		{
			std::cout << "You have to open the file first!";
		}
	}

}