#include "HelpCommand.h"

void HelpCommand::execute()
{
	std::cout << "List of commands:" << std::endl;

	std::cout << "print : print the json object" << std::endl;
	std::cout << "search <key> : get an array with all values that have this key" << std::endl;
	std::cout << "set <path> <string> : sets the value of the field at the path to the input string" << std::endl;
	std::cout << "create <path> <string> : sets the value of the field at the path to the input string. If the path does not exist, it is created" << std::endl;
	std::cout << "delete <path> : Deletes the field at that path" << std::endl;
	std::cout << "move <from> <to> : Moves the field from the <from> location to the <to> location" << std::endl;
	std::cout << "save [<path>] : saves the current state of the json. If path is inputed the json object at that path is saved" << std::endl;
	std::cout << "saveas <file> [<path>] : saves the current state of the json as <filename>. If path is inputed the json object at that path is saved" << std::endl;
	std::cout << "close : closes the opened file without saving" << std::endl;
	std::cout << "exit : terminates the program" << std::endl;
}
