#pragma once
#include "Command.h"
#include "MyString.h"

class SaveCommand : public Command
{
	SharedPtr<Object> mainObj;
	MyString path;
public:
	SaveCommand(SharedPtr<Object> mainObj);
	SaveCommand(SharedPtr<Object> mainObj, MyString&& path);
	void execute() override;
};