#include "PrintCommand.h"

PrintCommand::PrintCommand(SharedPtr<Object> mainObj) : mainObj(mainObj)
{
}

void PrintCommand::execute()
{
	mainObj->print(std::cout);
}
