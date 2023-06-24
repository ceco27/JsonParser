#include "CommandExecutor.h"

CommandExecutor::CommandExecutor(Command* onEnd)
{
	this->onEnd = onEnd;
}

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
	std::cout << "end";
	if (onEnd)
		onEnd->execute();
}
