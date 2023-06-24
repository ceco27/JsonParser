#include "CommandExecutor.h"

void CommandExecutor::setCommand(Command* command)
{
	this->command = command;
}

void CommandExecutor::execute()
{
	command->execute();
}

CommandExecutor::~CommandExecutor()
{
}
