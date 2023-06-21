#pragma once
#include "Command.h"

class PrintCommand : public Command
{
	SharedPtr<Object> mainObj;
public:
	PrintCommand(SharedPtr<Object> mainObj);
	void execute() override;
};