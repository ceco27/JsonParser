#pragma once
#include "Command.h"
#include "MyString.h"

class SetCommand : public Command
{
	SharedPtr<Object> mainObj;
	MyString path;
	MyString value;
public:
	SetCommand(SharedPtr<Object> mainObj, MyString&& path, MyString&& value);
	void execute() override;
};