#include "HelpCommand.h"

void HelpCommand::execute()
{
	std::cout << "List of commands:" << std::endl;

	std::cout << "print: print the json object" << std::endl;
	std::cout << "search <key>: get an array with all values that have this key" << std::endl;
}
