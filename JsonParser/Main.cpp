#include <iostream>
#include <sstream>
#include "CommandExecutor.h"
#include "CommandFactory.h"
#include "SaveCommand.h"
#include "OpenCommand.h"

int main()
{
	
	while (true)
	{
		try
		{
			std::cout << "Enter command:" << std::endl;
			char inputLine[128];
			std::cin.getline(inputLine, 1024);

			std::stringstream input(inputLine);

			char inputCommand[32];
			char fileName[32];
			input.getline(inputCommand, 32, ' ');
			input.getline(fileName, 32);
			if (strcmp(inputCommand, "open") == 0)
			{
				CommandExecutor executor;
				Object* object = new Object(MyString(), 0, fileName);
				executor.setCommand(new OpenCommand(object, fileName));
				executor.execute();
				while (true)
				{
					try
					{
						executor.setCommand(CommandFactory::getInstance().getCommand(object));
						executor.execute();
					}
					catch (int returnCode)
					{
						if (returnCode == -1)
						{
							break;
						}

						throw returnCode;
					}
					catch (std::exception& e)
					{
						std::cout << e.what();
					}
				}
			}
			else if (strcmp(inputCommand, "exit") == 0)
			{
				throw - 2;
			}
			else
			{
				std::cout << "You have to open the file first!" << std::endl;
			}
		}
		catch (int returnCode)
		{
			break;
		}
	}
	
}