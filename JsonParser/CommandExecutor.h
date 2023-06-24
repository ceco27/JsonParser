#pragma once
#include "Command.h"
class CommandExecutor
{
	Command* command = nullptr;
public:
	CommandExecutor() = default;
	CommandExecutor(const CommandExecutor&) = delete;
	CommandExecutor& operator=(const CommandExecutor&) = delete;
	void setCommand(Command* command);
	void execute();
	~CommandExecutor();
};