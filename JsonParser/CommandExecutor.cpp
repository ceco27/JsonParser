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
	if (onEnd)
		onEnd->execute();
}
