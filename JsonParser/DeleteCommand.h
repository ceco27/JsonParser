#pragma once
#include "Command.h"
#include "MyString.h"

class DeleteCommand : public Command
{
	SharedPtr<Object> mainObj;
	MyString path;
public:
	DeleteCommand(SharedPtr<Object> mainObj, MyString&& path);
	void execute() override;
};