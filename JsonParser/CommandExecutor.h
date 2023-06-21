#pragma once
#include "Command.h"
class CommandExecutor
{
	Command* command;
	Command* onEnd;
public:
	CommandExecutor() = default;
	CommandExecutor(Command* onEnd);
	CommandExecutor(const CommandExecutor&) = delete;
	CommandExecutor& operator=(const CommandExecutor&) = delete;
	void setCommand(Command* command);
	void execute();
	~CommandExecutor();
};